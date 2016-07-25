function gameLogic() {
	var canvas = document.querySelector("canvas");
	var ctx = canvas.getContext("2d");
	
	var LOADING = 0;
	var PLAYING = 1;
	var GAMEEND = 2;
	var gameState = LOADING;
	
	var assetsToLoad =  [];
	var assetsLoaded = 0;
	
	var image = new Image();
	image.src = "alienArmada.png";
	image.addEventListener("load", loadHandler);
	assetsToLoad.push(image);
	
	var sprites = [];
	
	var background = new SpriteObject();
		background.srcX = 0;
		background.srcY = 32;
		background.srcW = 480;
		background.srch = 320;
		background.w = 480;
		background.h = 320;

		sprites.push(background);
	
	var cannon = new SpriteObject();
		cannon.srcX = 0;
		cannon.srcY = 0;
		cannon.srcW = 32;
		cannon.srch = 32;
		cannon.w = 32;
		cannon.h = 32;

		sprites.push(cannon);
		
	var enemy = new SpriteObject();
		enemy.srcX = 32;
		enemy.srcY = 0;
		enemy.srcW = 32;
		enemy.srch = 32;
		enemy.w = 32;
		enemy.h = 32;

		sprites.push(enemy);

	var explosion = new SpriteObject();
		explosion.srcX = 64;
		explosion.srcY = 0;
		explosion.srcW = 32;
		explosion.srch = 32;
		explosion.w = 32;
		explosion.h = 32;

		sprites.push(explosion);

	
	
	function loadHandler (){
		assetsLoaded += 1;
		
		if (assetsLoaded == assetsToLoad.length)
		{
			gameState = PLAYING;
			image.removeEventListener("load", loadHandler); 
		}
	}
	
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
	
	function playGame (){
		
	}
	
	function endGame(){
		
	}
	
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
	update();
}