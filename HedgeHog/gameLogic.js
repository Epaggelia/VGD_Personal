function gameLogic() {
	var canvas = document.querySelector("canvas");
	var ctx = canvas.getContext("2d");

	var assetsToLoad = [];
	var assetsLoaded = 0;

	var sprites = [];

	var image = new Image();
	image.addEventListener("load", loadHandler);
	image.src = "hedgehogApocalypse.png";
	assetsToLoad.push(image);

	//Game states
	var LOADING = 0;
	var BUILD_MAP = 1;
	var PLAYING = 2;
	var OVER = 3;
	var gameState = LOADING;

	//keycodes
	var LEFT = 37;
	var RIGHT = 39;
	var SPACE = 32;

	//Direction flags
	var moveRight = false;
	var moveLeft = false;
	var jumping = false;

	var HedgehogObject = function () {
		this.sprite = new SpriteObject();
		this.NORMAL = [1, 0];
		this.SQUASHED = [2, 0];
		this.state = this.NORMAL;

		this.update = function () {
			this.sprite.srcX = this.state[0] * this.sprite.srcW;
			this.sprite.srcY = this.state[1] * this.sprite.srcH;
		};

		this.speed = 1;
	};

	var map =
			[
				[7, 7, 8, 9, 7, 7, 7, 8, 9, 7, 7, 7, 8, 9, 7, 7],
				[8, 9, 7, 7, 4, 9, 7, 7, 7, 8, 9, 7, 7, 7, 8, 5],
				[4, 7, 7, 7, 7, 7, 8, 9, 7, 7, 7, 8, 9, 7, 4, 4],
				[7, 7, 4, 7, 7, 4, 4, 4, 4, 7, 7, 7, 7, 7, 7, 7],
				[8, 9, 4, 7, 7, 7, 7, 8, 9, 7, 7, 4, 8, 9, 7, 7],
				[7, 4, 4, 4, 7, 8, 9, 7, 7, 7, 4, 4, 7, 7, 4, 8],
				[9, 7, 8, 9, 7, 7, 7, 8, 9, 4, 7, 4, 9, 7, 7, 7],
				[7, 7, 7, 7, 7, 4, 4, 7, 7, 7, 7, 4, 4, 4, 4, 7],
				[8, 9, 7, 7, 7, 7, 7, 7, 7, 8, 9, 7, 7, 8, 9, 7],
				[7, 7, 4, 4, 4, 4, 7, 7, 4, 7, 7, 7, 7, 7, 7, 7],
				[7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 7, 7, 7, 7, 7, 7],
				[6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6]
			];

	//The game objects map

	var gameObjects =
			[
				[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
				[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
				[0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0],
				[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
				[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
				[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
				[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0],
				[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
				[0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
				[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
				[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
				[0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0]
			];

	//tile numbers
	var EMPTY = 0;
	var CAT = 1;
	var HEDGEHOG = 2;
	var BOX = 4;
	var DOOR = 5;
	var GRASS = 6;
	var SKY = 7;

	var SIZE = 64;

	var ROWS = map.length;
	var COLS = map[0].length;

	var tileSheetColumns = 3;

	function loadHandler() {
		assetsLoaded += 1;

		if (assetsLoaded == assetsToLoad.length)
		{
			image.removeEventListener("load", loadHandler);
			gameState = BUILD_MAP; // temporary. Build_Map needed

			window.addEventListener("keydown", function (e) {
				switch (e.keyCode) {
					case LEFT:
						moveLeft = true;
						break;
					case RIGHT:
						moveRight = true;
						break;
					case SPACE:
						jumping = true;
						break;
				}
			});

			window.addEventListener("keyup", function (e) {
				switch (e.keyCode) {
					case LEFT:
						moveLeft = false;
						break;
					case RIGHT:
						moveRight = false;
						break;
					case SPACE:
						jumping = false;
						break;
				}
			});
		}
	}


	var cat = null;
	var hog = null;

	function update() {
		window.requestAnimationFrame(update);

		switch (gameState) {
			case LOADING:
				console.log("Loading...");
				break;
			case BUILD_MAP:
				buildMap(map);
				buildMap(gameObjects);
				gameState = PLAYING;
				break;
			case PLAYING:
				playGame();
				break;
			case OVER:
				//to do later
				break;
		}
		render();
	}

	function buildMap(levelMap) {
		for (row = 0; row < ROWS; row++)
		{
			for (col = 0; col < COLS; col++)
			{
				var currentTile = levelMap[row][col];

				if (currentTile != EMPTY)
				{
					var tileSheetX = Math.floor((currentTile - 1) % tileSheetColumns) * SIZE;
					var tileSheetY = Math.floor((currentTile - 1) / tileSheetColumns) * SIZE;

					switch (currentTile) {
						case CAT:
							cat = new SpriteObject();
							cat.srcX = tileSheetX;
							cat.srcY = tileSheetY;
							cat.srcW = 64;
							cat.srcH = 64;
							cat.x = col * SIZE;
							cat.y = row * SIZE;
							cat.w = 64;
							cat.h = 64;
							sprites.push(cat);
							break;
						case HEDGEHOG:
							var hedgehog = new HedgehogObject();
							hedgehog.sprite.srcX = tileSheetX;
							hedgehog.sprite.srcY = tileSheetY;
							hedgehog.sprite.srcW = 64;
							hedgehog.sprite.srcH = 64;
							hedgehog.sprite.x = col * SIZE;
							hedgehog.sprite.y = row * SIZE;
							hedgehog.sprite.w = 64;
							hedgehog.sprite.h = 64;
							sprites.push(hedgehog.sprite);
							break;
						case BOX:
							var box = new SpriteObject();
							box.srcX = tileSheetX;
							box.srcY = tileSheetY;
							box.srcW = 64;
							box.srcH = 64;
							box.x = col * SIZE;
							box.y = row * SIZE;
							box.w = 64;
							box.h = 64;
							sprites.push(box);
							break; 
						case DOOR:
							var door = new SpriteObject();
							door.srcX = tileSheetX;
							door.srcY = tileSheetY;
							door.srcW = 64;
							door.srcH = 64;
							door.x = col * SIZE;
							door.y = row * SIZE;
							door.w = 64;
							door.h = 64;
							sprites.push(door);
							break; 
						default:
							var sprite = new SpriteObject();
							sprite.srcX = tileSheetX;
							sprite.srcY = tileSheetY;
							sprite.srcW = 64;
							sprite.srcH = 64;
							sprite.x = col * SIZE;
							sprite.y = row * SIZE;
							sprite.w = 64;
							sprite.h = 64;
							sprites.push(sprite);
					}
				}
			}
		}
	}

	function playGame() {
		if (moveLeft && !moveRight)
		{
			cat.ax = -0.2;
			cat.friction = 1;
		}
		else if (!moveLeft && moveRight)
		{
			cat.ax = 0.2;
			cat.friction = 1;
		}
		
		 if (!moveLeft && !moveRight)
		{
			cat.ax = 0;
			cat.friction = 0.96;
		}
		
		cat.vx += cat.ax;
		cat.vx *= cat.friction;
		cat.x += cat.vx;
	}

	function render() {
		ctx.clearRect(0, 0, canvas.width, canvas.height);

		for (i = 0; i < sprites.length; i++)
		{
			var sprite = sprites[i];

			if (sprite.visible)
			{
				ctx.drawImage(image,
						sprite.srcX, sprite.srcY,
						sprite.srcW, sprite.srcH,
						Math.floor(sprite.x), Math.floor(sprite.y),
						sprite.w, sprite.h);
			}
		}
	}
	update();
}