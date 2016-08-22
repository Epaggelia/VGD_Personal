function gameLogic() {
	var canvas = document.querySelector("canvas");
	var ctx = canvas.getContext("2d");

	var music = document.querySelector("#music");
	music.addEventListener("canplaythrough", loadHandler);

	var shootSFX = document.querySelector("#shoot");
	shootSFX.addEventListener("canplaythrough", loadHandler);

	var explosionSFX = document.querySelector("#explosion");
	explosionSFX.addEventListener("canplaythrough", loadHandler);

	//create new aliens
	var AlienObject = function () {
		this.sprite = new SpriteObject();
		this.NORMAL = 1;
		this.EXPLODED = 2;
		this.state = this.NORMAL;

		this.update = function () {
			this.sprite.srcX = this.state * this.sprite.srcW;
		};
	};

	//game states
	var LOADING = 0;
	var MENU = 1;
	var PLAYING = 2;
	var GAMEEND = 3;
	var gameState = LOADING;
	
	var gameOver = false;

	//keycodes
	var LEFT = 37;
	var RIGHT = 39;
	var SPACE = 32;

	//player states
	var moveLeft = false;
	var moveRight = false;
	var shoot = false;
	var score = 0;

	//alien spawn timing
	var alienFrequency = 100;
	var alienTimer = 0;

	//missile spawn timing
	var missileFireRate = 20;						//Personal method
	var missileTimer = 20;							//Personal method

	//startup info
	var assetsToLoad = [];
	var assetsLoaded = 0;

	//get image info
	var image = new Image();
		image.src = "alienArmada.png";
		image.addEventListener("load", loadHandler);
		assetsToLoad.push(image);

	music.load();
	assetsToLoad.push(music);
	shootSFX.load();
	assetsToLoad.push(shootSFX);
	explosionSFX.load();
	assetsToLoad.push(explosionSFX);

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

	var title = new SpriteObject();
		title.srcY = 352;
		title.srcW = 275;
		title.srcH = 145;
		title.x = 106;
		title.y = 50;
		title.w = 275;
		title.h = 145;
		sprites.push(title);

	var playButton = new SpriteObject();
		playButton.srcX = 275;
		playButton.srcY = 352;
		playButton.srcW = 108;
		playButton.srcH = 54;
		playButton.x = 187;
		playButton.y = 213;
		playButton.w = 108;
		playButton.h = 54;
		sprites.push(playButton);

	//clip cannon from image file
	var cannon = new SpriteObject();
		cannon.x = canvas.width / 2 - cannon.halfWidth();
		cannon.y = 280;
		cannon.visible = false;
		sprites.push(cannon);

	var messages = [];
	var scoreMessageStartX = 440;

	var scoreMessage = new MessageObject();
		scoreMessage.font = "normal bold 30px emulogic";
		scoreMessage.fontStyle = "White";
		scoreMessage.x = scoreMessageStartX;
		scoreMessage.y = 40;
		scoreMessage.visible = false;

	var gameOverMessage = new MessageObject();
		gameOverMessage.font = "normal bold 20px emulogic";
		gameOverMessage.fontStyle = "White";
		gameOverMessage.x = 90;
		gameOverMessage.y = 120;
		gameOverMessage.visible = false;

	messages.push(scoreMessage);
	messages.push(gameOverMessage);
	
	window.addEventListener("mousedown", clickHandler);
	
	function clickHandler (e){
		var mouseX = e.pageX - canvas.offsetLeft;
		var mouseY = e.pageY - canvas.offsetTop;
		
		if (hitTestPoint(mouseX,mouseY, playButton))
		{
			window.removeEventListener("mousedown",clickHandler);
			
			title.visible = false;
			playButton.visible = false;
			cannon.visible = true;
			scoreMessage.visible = true;
			gameOverMessage.visible = false;
			gameState = PLAYING;
			gameOver = false;
		}
	}

	//load check
	function loadHandler() {
		assetsLoaded += 1;

		if (assetsLoaded == assetsToLoad.length)
		{
			gameState = MENU;
			image.removeEventListener("load", loadHandler);
			music.removeEventListener("canplaythrough", loadHandler);
			shootSFX.removeEventListener("canplaythrough", loadHandler);
			explosionSFX.removeEventListener("canplaythrough", loadHandler);
			music.play();
			music.volume = 0.3;

			//key down input reader
			window.addEventListener("keydown", function (e) {
				switch (e.keyCode) {
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
			window.addEventListener("keyup", function (e) {
				switch (e.keyCode) {
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
	function update() {
		window.requestAnimationFrame(update);

		switch (gameState) {
			case LOADING:
				console.log("Loading...");
				break;
			case MENU:
				showMenu();
				break;
			case PLAYING:
				playGame();
				break;
			case GAMEEND:
				endGame();
				break;
			default:
				console.log("Something went wrong...");
		}
		render();
	}

	function showMenu() {
		//reset game variables to default
		if (!gameOver){
			window.addEventListener("mousedown", clickHandler);
			
			playButton.visible = true;
			gameOver = true;
			
			alienFrequency =100;
			score = 0;
			
			cannon.x = canvas.width / 2 - cannon.w/2;
			
			for (i=0;i<aliens.length;i++){
				var alien = aliens[i];
				removeObject (alien, aliens);
				removeObject (alien.sprite, sprites);
				i-=1;
			}
			
			for (i=0;i<missiles.length;i++){
				var missile = missiles[i];
				removeObject (missile, missiles);
				removeObject (missile, sprites);
				i-=1;
			}
		}
	}

	//
	function playGame() {

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
		cannon.x = Math.max(0, Math.min(cannon.x + cannon.vx, canvas.width - cannon.w));

		//missile spawn timer / firerate limiter
		missileTimer++;								//Personal method
		if (shoot)									//Personal method
		{											//Personal method
			if (missileTimer >= missileFireRate)	//Personal method
			{										//Personal method
				fireMissile();
				missileTimer = 0;					//Personal method
			}										//Personal method
		}											//Personal method

		for (i = 0; i < missiles.length; i++)
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

			if (alienFrequency > 40)
			{
				alienFrequency -= 1;
			}
		}

		//alien movement
		for (i = 0; i < aliens.length; i++)
		{
			var alien = aliens[i];

			for (j = 0; j < missiles.length; j++)
			{
				var missile = missiles[j];

				if (alien.state == alien.NORMAL)
				{
					if (hitTestRectangle(missile, alien.sprite))
					{
						removeObject(missile, sprites);
						removeObject(missile, missiles);
						destroyAlien(alien);
						j -= 1;
						score += 1;
					}
				}
			}
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

	function endGame() {
		gameOverMessage.visible = true;
		gameOverMessage.text = "EARTH DESTROYED";
		gameState = MENU;
	}

	//clear canvas and fill with image clips
	function render() {
		ctx.clearRect(0, 0, canvas.width, canvas.height);

		for (i = 0; i < sprites.length; i++)
		{
			var sprite = sprites[i];

			if (sprite.visible)
			{
				ctx.drawImage
						(
								image,
								sprite.srcX, sprite.srcY, // clip source position
								sprite.srcW, sprite.srcH, // clip source size
								Math.floor(sprite.x), Math.floor(sprite.y), //draw position
								sprite.w, sprite.h //draw size
								);
			}
		}

		scoreMessage.x = scoreMessageStartX - ((score.toString().length) - 1) * 30;
		scoreMessage.text = score;

		for (i = 0; i < messages.length; i++)
		{
			var message = messages[i];

			if (message.visible)
			{
				ctx.font = message.font;
				ctx.fillStyle = message.fontStyle;
				ctx.textBaseLine = message.textBaseLine;

				ctx.fillText(message.text, message.x, message.y);
			}
		}
	}

	//create alien
	function makeAlien() {
		var alien = new AlienObject();
		alien.sprite.srcX = 32;
		alien.sprite.y = -alien.sprite.h;
		alien.sprite.x = Math.floor(Math.random() * 15) * alien.sprite.w;
		alien.sprite.vy = 1;
		sprites.push(alien.sprite);
		aliens.push(alien);
	}

	//create missile
	function fireMissile() {
		shootSFX.currentTime = 0;
		shootSFX.play();

		var missile = new SpriteObject();
		missile.srcX = 96;
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

	function destroyAlien(alien)
	{
		alien.state = alien.EXPLODED;
		alien.update();

		explosionSFX.currentTime = 0;
		explosionSFX.play();

		setTimeout(function () {
			removeObject(alien.sprite, sprites);
			removeObject(alien, aliens);
		}, 1000);
	}


	function removeObject(objectToRemove, array)
	{
		var index = array.indexOf(objectToRemove);

		//indexOf will return -1 if it could not find the object
		if (index != -1)
		{
			array.splice(index, 1);
		}
	}

	update();
}