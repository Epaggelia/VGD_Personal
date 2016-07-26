function gameLogic() {
	var canvas = document.querySelector("canvas");
	var ctx = canvas.getContext("2d");
	
	//create new aliens
	var AlienObject = function () {
		this.sprite = new SpriteObject();
		this.NORMAL = 1;
		this.EXPLODED = 2;
		this.state = this.NORMAL;
	};
	
	//game states
	var LOADING = 0;
	var PLAYING = 1;
	var GAMEEND = 2;
	var gameState = LOADING;
	
	//keycodes
	var LEFT = 37;
	var RIGHT = 39;
	var SPACE = 32;
	
	//player states
	var moveLeft = false;
	var moveRight = false;
	var shoot = false;
	
	//alien spawn timing
	var alienFrequency = 100;
	var alienTimer = 0;
	
	//alien spawn timing
	var missileFireRate = 20;
	var missileTimer = 20;
	
	//startup info
	var assetsToLoad =  [];
	var assetsLoaded = 0;
	
	//get image info
	var image = new Image();
	image.src = "alienArmada.png";
	image.addEventListener("load", loadHandler);
	assetsToLoad.push(image);
	
	var sprites = []; // array for drawing all sprites
	var aliens = []; // array for updating aliens
	var missiles = []; // array for updating missiles
	
	//clip background from image file
	var background = new SpriteObject();
		background.srcX = 0;
		background.srcY = 32;
		background.srcW = 480;
		background.srcH = 320;
		background.w = 480;
		background.h = 320;

		sprites.push(background);
	
	//clip cannon from image file
	var cannon = new SpriteObject();
		cannon.x = canvas.width / 2 - cannon.halfWidth();
		cannon.y = 280;
		sprites.push(cannon);
	
	//clip explosion from image file
	var explosion = new SpriteObject();
		explosion.srcX = 64;
		//incomplete
		sprites.push(explosion);

	
	//load check
	function loadHandler (){
		assetsLoaded += 1;
		
		if (assetsLoaded == assetsToLoad.length)
		{
			gameState = PLAYING;
			image.removeEventListener("load", loadHandler); 
			
			//key down input reader
			window.addEventListener("keydown",function (e){
				switch (e.keyCode){
					case LEFT:
						moveLeft = true;
						break;
					case RIGHT:
						moveRight = true;
						break;
					case SPACE:
						shoot = true;
						break;
				}
			});
			
			//key release input reader
			window.addEventListener("keyup",function (e){
				switch (e.keyCode){
					case LEFT:
						moveLeft = false;
						break;
					case RIGHT:
						moveRight = false;
						break;
					case SPACE:
						shoot = false;
						break;
				}
			});
		}
	}
	
	//runs game functoins
	function update (){
		window.requestAnimationFrame(update);
		
		switch(gameState){
			case LOADING:
				console.log("Loading...");
				break;
			case PLAYING:
				playGame();
				break;
			case GAMEEND:
				endGame ();
				break;
			default:
				console.log("Something went wrong...");
		}
		render();
	}
	
	//
	function playGame (){
		
		if (moveLeft && !moveRight)
		{
			cannon.vx = -8;
		}
		
		if (!moveLeft && moveRight)
		{
			cannon.vx = 8;
		}
		
		if (!moveLeft && !moveRight)
		{
			cannon.vx = 0;
		}
		
		//locks cannon movement onto canvas width
		cannon.x = Math.max(0,Math.min(cannon.x + cannon.vx, canvas.width - cannon.w));
		
		missileTimer++; 
		if (shoot)
		{
			if (missileTimer >= missileFireRate)
			{
				fireMissile();
				missileTimer = 0;
			}
		}
		
		for (i=0;i<missiles.length;i++)
		{
			var missile = missiles[i];
			
			missile.y += missile.vy;
		}
		
		//alien spawn timer
		alienTimer++; 
		if (alienTimer >= alienFrequency)
		{
			makeAlien();
			alienTimer = 0;
		}
		
		//alien movement
		for (i=0;i<aliens.length;i++)
		{
			var alien = aliens[i];
			
			if (alien.state == alien.NORMAL)
			{
				alien.sprite.y += alien.sprite.vy;
			}
			
			if (alien.sprite.y > canvas.height)
			{
				gameState = GAMEEND;
			}
		}
	}
	
	function endGame(){
		
	}
	
	//clear canvas and fill with image clips
	function render (){
		ctx.clearRect(0,0,canvas.width,canvas.height);
		
		for (i=0;i<sprites.length;i++)
		{
			var sprite = sprites[i];
			
			ctx.drawImage
			(
				image, 
				sprite.srcX, sprite.srcY,  // clip source position
				sprite.srcW, sprite.srcH,  // clip source size
				Math.floor(sprite.x), Math.floor(sprite.y),	//draw position
				sprite.w,sprite.h //draw size
			);
		}
	}
	
	//create alien
	function makeAlien(){
		var alien = new AlienObject();
		alien.sprite.srcX = 32;
		alien.sprite.y = -alien.sprite.h;
		alien.sprite.x = Math.floor(Math.random()*15)*alien.sprite.w;
		alien.sprite.vy = 1;
		sprites.push(alien.sprite);
		aliens.push(alien);
	}
	
	//create missile
	function fireMissile() {
		var missile = new SpriteObject();
		missile.srcX  = 96;
		missile.srcW = 16;
		missile.srcH = 16;
		missile.w = 16;
		missile.h = 16;
		missile.vy = -8;
		
		missile.x = cannon.center().x - missile.halfWidth();
		missile.y = cannon.y - missile.h;
		
		sprites.push(missile);
		missiles.push(missile);
	}
	
	update();
}