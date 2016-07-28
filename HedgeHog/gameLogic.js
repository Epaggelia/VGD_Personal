function gameLogic() {
	var canvas = document.querySelector("canvas");
	var ctx = canvas.getContext("2d");

	var assetsToLoad = [];
	var assetsLoaded = 0;

	var sprites = [];

	var image = new Image();
	image.addEventListener("load", loadHandler);
	image.src = "hedgehogApocalyse.png";
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

	function loadHandler() {
		assetsLoaded += 1;

		if (assetsLoaded == assetsToLoad.length)
		{
			image.removeEventListener("load", loadHandler);
			gameState = PLAYING; // temporary. Build_Map needed

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
				//to do later
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

	function render() {
		ctx.clearRect(0, 0, canvas.width, canvas.height);
		
		for (i=0;i<sprite.length;i++){
			var sprite = sprites[i];
			
			if (sprite.visible) {
				ctx.drawImage(image,
					sprite.srcX, sprite.srcY,
					sprite.srcW, sprite.srcH,
					Math.floor(sprite.x), Math.floor(sprite.y),
					sprite.w, sprite.h);
			}
		}
	}
}