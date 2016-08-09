function gameLogic() {
	var canvas = document.querySelector("canvas");
	var ctx = canvas.getContext("2d");

	var assetsToLoad = [];
	var assetsLoaded = 0;

	var sprites = [];
	var blocks = [];
	var hogs = [];
	var messages = [];

	var hogsSquashed = 0;

	var cat = null;
	var door = null;
	var gameOverDisplay = null;
	var gameOverMessage = null;

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




	function update() {
		window.requestAnimationFrame(update);

		switch (gameState) {
			case LOADING:
				console.log("Loading...");
				break;
			case BUILD_MAP:
				buildMap(map);
				buildMap(gameObjects);
				createOtherObjects();
				gameState = PLAYING;
				break;
			case PLAYING:
				playGame();
				break;
			case OVER:
				endGame();
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
							hedgehog.sprite.vx = hedgehog.speed;
							sprites.push(hedgehog.sprite);
							hogs.push(hedgehog);
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
							blocks.push(box);
							break;
						case DOOR:
							door = new SpriteObject();
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

	function createOtherObjects()
	{
		gameOverDisplay = new SpriteObject();
		gameOverDisplay.srcY = 192;
		gameOverDisplay.srcW = 192;
		gameOverDisplay.srcH = 128;
		gameOverDisplay.w = 192;
		gameOverDisplay.h = 128;
		gameOverDisplay.x = canvas.width / 2 - gameOverDisplay.w / 2;
		gameOverDisplay.y = canvas.height / 2 - gameOverDisplay.h / 2;
		gameOverDisplay.visible = false;
		sprites.push(gameOverDisplay);

		gameOverMessage = new MessageObject();
		gameOverMessage.x = gameOverDisplay.x + 20;
		gameOverMessage.y = gameOverDisplay.y + 35;
		gameOverMessage.font = "bold 30px Helvetica";
		gameOverMessage.fillStype = "black";
		gameOverMessage.text = "";
		gameOverMessage.visible = false;
		messages.push(gameOverMessage);
	}

	function playGame() {

		if (jumping && cat.isOnGround)
		{
			cat.vy += cat.jumpForce;
			cat.ax = -0.2;
			cat.isOnGround = false;
			cat.friction = 1;
		}

		if (moveLeft && !moveRight)
		{
			cat.ax = -0.2;
			cat.friction = 1;
		} else if (!moveLeft && moveRight)
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
		cat.vy += cat.gravity;
		if (cat.isOnGround)
			cat.vx *= cat.friction;
		cat.x += cat.vx;
		cat.y += cat.vy;

		for (i = 0; i < blocks.length; i++)
		{
			var box = blocks[i];
			var collisionSide = blockRectangle(cat, box, false);

			if (collisionSide == "bottom" && cat.vy >= 0)
			{
				cat.isOnGround = true;
				cat.vy = -cat.gravity;
			} else if (collisionSide == "top" && cat.vy < 0)
			{
				cat.vy = 0;
			}

			if (collisionSide == "left" && cat.vx < 0)
			{
				cat.vx = 0;
			} else if (collisionSide == "right" && cat.vx > 0)
			{
				cat.vx = 0;
			}

			if (collisionSide != "bottom" && cat.vy > 0)
			{
				cat.isOnGround = false;
			}
		}

		for (i = 0; i < hogs.length; i++)
		{
			var hog = hogs[i];

			if (hog.state == hog.NORMAL)
			{
				hog.sprite.x += hog.sprite.vx;
				hog.sprite.y += hog.sprite.vy;
			}

			if (Math.floor(hog.sprite.x) % SIZE == 0 && Math.floor(hog.sprite.y) % SIZE == 0)
			{
				var hogColumn = Math.floor(hog.sprite.x / SIZE);
				var hogRow = Math.floor(hog.sprite.y / SIZE);

				if (hogRow < ROWS - 1)
				{
					var spaceBelowLeft = map[hogRow + 1] [hogColumn - 1];
					var spaceBelowRight = map[hogRow + 1] [hogColumn + 1];

					if (spaceBelowLeft != BOX || spaceBelowRight != BOX)
					{
						hog.sprite.vx *= -1;
					}

					if (hogColumn > 0)
					{
						var spaceLeft = map[hogRow][hogColumn - 1];
						if (spaceLeft == BOX)
						{
							hog.sprite.vx *= -1;
						}
					}
					if (hogColumn < COLS - 1)
					{
						var spaceRight = map[hogRow][hogColumn + 1];
						if (spaceRight == BOX)
						{
							hog.sprite.vx *= -1;
						}
					}

				}
			}

			if (hog.sprite.visible && hitTestCircle(cat, hog.sprite) && hog.state == hog.NORMAL)
			{
				if (cat.vy > 0)
				{
					blockCircle(cat, hog.sprite, true);
					squashHog(hog);
					hogsSquashed += 1;
				} else
				{
					gameState = OVER;
				}
			}
		}

		if (hitTestRectangle(cat, door))
		{
			if (hogsSquashed == 3)
			{
				gameState = OVER;
			}
		}

		if (cat.x < 0)
		{
			cat.vx = 0;
			cat.x = 0;
		} else if (cat.x + cat.w > canvas.width)
		{
			cat.vx = 0;
			cat.x = canvas.width - cat.w;
		}
		if (cat.y + cat.h > canvas.height)
		{
			cat.y = canvas.height - cat.h;
			cat.isOnGround = true;
			cat.vy = -cat.gravity;
		}
	}

	function endGame()
	{
		gameOverDisplay.visible = true;
		gameOverMessage.visible = true;

		if (hogsSquashed == 3)
		{
			gameOverMessage.text = "You Win!";
		} else
		{
			gameOverMessage.text = "You Lose!";
		}
	}

	function squashHog(hedgehog) {
		hedgehog.state = hedgehog.SQUASHED;
		hedgehog.update();

		setTimeout(function () {
			hedgehog.sprite.visible = false;
		}, 1000);
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
		for (i = 0; i < messages.length; i++)
		{
			var message = messages [i];

			if (message.visible)
			{
				ctx.font = message.font;
				ctx.fillStyle = message.fillStyle;
				ctx.textBaseline = message.textBaseline;
				ctx.fillText(message.text, message.x, message.y);

			}
		}
	}
	update();
}