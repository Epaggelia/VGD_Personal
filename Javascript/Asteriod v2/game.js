$(document).ready(function ()
{
	var canvas = $("#gameCanvas");
	var context = canvas.get(0).getContext("2d");
	var names = ["Jim", "Frank", "Bob", "Alice", "Will",
		"Rob", "Charley", "Tim", "Roger", "Matt",
		"Jane", "Kim", "Tom", "Joane", "Jeff",
		"Emily", "Jackson", "Mia", "Liam", "Mason",
		"Lucas", "Sophia", "Lily", "Emma", "Madelyn",
		"Aiden", "Noah", "Ava", "Logan", "Jacob",
		"Caden", "Isabella", "Ethan", "Olivia", "Zoe"
	];

	//canvas dimensions
	var canvasWidth = canvas.width();
	var canvasHeight = canvas.height();

	//Game UI
	var ui = $("#gameUI");
	var uiIntro = $("#gameIntro");
	var uiStats = $("#gameStats");
	var uiComplete = $("#gameComplete");
	var uiPlay = $("#gamePlay");
	var uiReset = $(".gameReset");
	var uiScore = $(".gameScore");
	var uiRockName = $(".gameRockName");

	//Game settings
	var playGame, asteroids, numAsteroids, player, score, scoreTimeout;

	//keyboard keycodes
	var arrowLeft = 37;
	var arrowUp = 38;
	var arrowRight = 39;
	var arrowDown = 40;
	var spacebar = 32;

	var playerSpeed = 6;

	// Asteroid information variables
	var x, y, radius, vx, vy, mass, push;

	var Asteroid = function (x, y, radius, vx, vy, mass, name)
	{
		this.name = name;
		this.x = x;
		this.y = y;
		this.radius = radius;
		this.vx = vx;
		this.vy = vy;
		this.mass = mass;
	};

	var Player = function (x, y)
	{
		this.x = x;
		this.y = y;
		this.width = 24;
		this.height = 24;
		this.halfWidth = this.width / 2;
		this.halfHeight = this.height / 2;

		this.vx = 0;
		this.vy = 0;

		this.moveRight = false;
		this.moveLeft = false;
		this.moveUp = false;
		this.moveDown = false;
		this.shooting = false;

		this.flameLength = 20;
	};

	function randomNegitive(num)
	{
		var tmpRandom = Math.random() > 0.5 ? -1 : 1;
		return num * tmpRandom;
	}

	//creates Asteroid information
	function createAsteroidVariables(tmpX, tmpY, tmpRadius, tmpVx, tmpVy, tmpMass, tmpName, pushFlag)
	{
		tmpVx = 2 + (Math.random() * 3);
		tmpVy = 2 + (Math.random() * 3);

		tmpRadius = 5 + (Math.random() * 10);
		tmpX = Math.floor((canvasWidth / 2) + ((randomNegitive(1)) * (canvasWidth / 2 + (Math.random() * canvasWidth) + tmpRadius)));
		tmpY = Math.floor((canvasHeight / 2) + ((randomNegitive(1)) * (canvasHeight / 2 + (Math.random() * canvasHeight) + tmpRadius)));
		if (tmpX > canvasWidth)
		{
			tmpVx = randomNegitive(tmpVx);
		}
		if (tmpY > canvasHeight)
		{
			tmpVy = randomNegitive(tmpVy);
		}

		var name = names[tmpName];

		tmpMass = tmpRadius / 2;

		if (pushFlag)
		{
			asteroids.push(new Asteroid(tmpX, tmpY, tmpRadius, tmpVx, tmpVy, tmpMass, name));
		}
		else
		{
			asteroids[tmpName].x = tmpX;
			asteroids[tmpName].y = tmpY;
			asteroids[tmpName].name = name;
			asteroids[tmpName].vx = tmpVx;
			asteroids[tmpName].vy = tmpVy;
			asteroids[tmpName].mass = tmpMass;
		}
	}

	function asteroidName(object, e)
	{
		context.fillStyle = "#333";
		context.textAlign = "center";
		context.font = Math.floor(object.radius) + 10 + "px Arial";
		context.fillText(asteroids[e].name !== null ? asteroids[i].name : "No-Name", object.x, object.y - object.radius);
	}

	function drawAsteroid(object)
	{
		context.fillStyle = "rgb(255,255,255)";
		context.beginPath();
		context.arc(object.x, object.y, object.radius, 0, Math.PI * 2, true);
		context.closePath();
		context.fill();
	}

	function asteroidCrash(object)
	{
		for (j = i + 1; j < asteroids.length; j++)
		{
			var object2 = asteroids[j];

			var dx = object2.x - object.x;
			var dy = object2.y - object.y;
			var distance = Math.sqrt(dx * dx + dy * dy);

			if (distance <= object2.radius + object.radius)
			{
				var angle = Math.atan2(dy, dx);
				var sine = Math.sin(angle);
				var cosine = Math.cos(angle);

				var x = 0;
				var y = 0;

				var x2 = dx * cosine + dy * sine;
				var y2 = dy * cosine - dx * sine;

				var vx = object.vx * cosine + object.vy * sine;
				var vy = object.vy * cosine - object.vx * sine;
				var vx2 = object2.vx * cosine + object2.vy * sine;
				var vy2 = object2.vy * cosine - object2.vx * sine;

				var vTotal = vx - vx2;
				vx = ((object.mass - object2.mass) * vx + 2 * object2.mass * vx2) /
						(object.mass + object2.mass);
				vx2 = vTotal + vx;
				x2 = x + (object.radius + object2.radius);

				object.x = object.x + (x * cosine - y * sine);
				object.y = object.y + (y * cosine + x * sine);
				object2.x = object.x + (x2 * cosine - y2 * sine);
				object2.y = object.y + (y2 * cosine + x2 * sine);

				object.vx = vx * cosine - vy * sine;
				object.vy = vy * cosine + vx * sine;
				object2.vx = vx2 * cosine - vy2 * sine;
				object2.vx = vy2 * cosine + vx2 * sine;
			}
		}
	}

	function drawRocket(object)
	{
		context.fillStyle = "rgb(255,0,0)";
		context.beginPath();
		context.arc(object.x, object.y, object.halfWidth, 0, Math.PI * 2, true);
		context.closePath();
		context.fill();
	}

	function drawFlame(object, direction)
	{

		//flame flicker
		if (object.flameLength === 20)
		{
			object.flameLength = 15;
		}
		else
		{
			object.flameLength = 20;
		}

		context.save();
		context.translate(object.x, object.y);

		if (direction === "right")
		{
			context.rotate(0 * Math.PI / 180);
		}
		else if (direction === "left")
		{
			context.rotate(180 * Math.PI / 180);
		}
		else if (direction === "down")
		{
			context.rotate(90 * Math.PI / 180);
		}
		else if (direction === "up")
		{
			context.rotate(-90 * Math.PI / 180);
		}

		context.fillStyle = "orange";
		context.beginPath();
		context.moveTo(0 - object.halfWidth, -5);
		context.lineTo(-object.flameLength - object.halfWidth, 0);
		context.lineTo(0 - object.halfWidth, 5);
		context.closePath();
		context.fill();

		context.restore();
	}

	// reset and start the gameCanvas
	function startGame()
	{
		asteroids = new Array();
		numAsteroids = 10;
		score = 0;
		player = new Player(150, canvasHeight / 2);

		//create asteroid variable values
		for (i = 0; i < numAsteroids; i++)
		{
			createAsteroidVariables(x, y, radius, vx, vy, mass, i, true);
		}

		//key press listeners
		$(window).keydown(function (e)
		{
			var keyCode = e.keyCode;

			//press a key to start the game
			if (!playGame)
			{
				playGame = true;
				animate();
				timer();
			}

			//key -> direction
			if (keyCode === arrowRight)
			{
				player.moveRight = true;
			}
			else if (keyCode === arrowLeft)
			{
				player.moveLeft = true;
			}
			else if (keyCode === arrowUp)
			{
				player.moveUp = true;
			}
			else if (keyCode === arrowDown)
			{
				player.moveDown = true;
			}
			if (keyCode === spacebar)
			{
				player.shooting = true;
			}
		});

		//key release
		$(window).keyup(function (e)
		{
			var keyCode = e.keyCode;

			if (keyCode === arrowRight)
			{
				player.moveRight = false;
			}
			else if (keyCode === arrowLeft)
			{
				player.moveLeft = false;
			}
			else if (keyCode === arrowUp)
			{
				player.moveUp = false;
			}
			else if (keyCode === arrowDown)
			{
				player.moveDown = false;
			}
			if (keyCode === spacebar)
			{
				player.shooting = false;
			}

		});

		//reset game stats
		uiScore.html("0");
		uiStats.show();

		// set up initial game settings
		playGame = false;

		//start the animation loop
		animate();
	}

	//inititialize the game environment
	function init()
	{
		uiStats.hide();
		uiComplete.hide();

		uiPlay.click(function (e)
		{
			e.preventDefault();
			uiIntro.hide();
			startGame();
		});

		uiReset.click(function (e)
		{
			e.preventDefault();
			uiComplete.hide();
			$(window).unbind("keyup");
			$(window).unbind("keydown");
			clearTimeout(scoreTimeout);
			startGame();
		});
	}

	function timer()
	{
		if (playGame)
		{
			scoreTimeout = setTimeout(function ()
			{
				uiScore.html(++score);
				if (score % 5 === 0)
				{
					numAsteroids += 5;
				}
				timer();
			}, 1000);
		}
	}

	//animation loop that does all the fun stuff
	function animate()
	{
		//clear
		context.clearRect(0, 0, canvasWidth, canvasHeight);

		var asteroidsLength = asteroids.length;
		for (i = 0; i < asteroidsLength; i++)
		{
			var tmpAsteroid = asteroids[i];

			//console.log (asteroids[i].name,"\n x: "+tmpAsteroid.x,"\n y: "+tmpAsteroid.y,"\n Vx: "+tmpAsteroid.vx,"\n Vy: "+tmpAsteroid.vy);

			tmpAsteroid.x += tmpAsteroid.vx;
			tmpAsteroid.y += tmpAsteroid.vy;

			//asteroid off edge resets
			if (tmpAsteroid.x + tmpAsteroid.radius < 0 && tmpAsteroid.vx < 0)
			{
				createAsteroidVariables(tmpAsteroid.x, tmpAsteroid.y, tmpAsteroid.radius, tmpAsteroid.vx, tmpAsteroid.vy, tmpAsteroid.mass, i, false);
			}
			else if (tmpAsteroid.x - tmpAsteroid.radius > canvasWidth && tmpAsteroid.vx > 0)
			{
				createAsteroidVariables(tmpAsteroid.x, tmpAsteroid.y, tmpAsteroid.radius, tmpAsteroid.vx, tmpAsteroid.vy, tmpAsteroid.mass, i, false);
			}
			if (tmpAsteroid.y + tmpAsteroid.radius < 0 && tmpAsteroid.vy < 0)
			{
				createAsteroidVariables(tmpAsteroid.x, tmpAsteroid.y, tmpAsteroid.radius, tmpAsteroid.vx, tmpAsteroid.vy, tmpAsteroid.mass, i, false);
			}
			else if (tmpAsteroid.y - tmpAsteroid.radius > canvasHeight && tmpAsteroid.vy > 0)
			{
				createAsteroidVariables(tmpAsteroid.x, tmpAsteroid.y, tmpAsteroid.radius, tmpAsteroid.vx, tmpAsteroid.vy, tmpAsteroid.mass, i, false);
			}

			//chash checker calculations
			var dx = player.x - tmpAsteroid.x;
			var dy = player.y - tmpAsteroid.y;
			var distance = Math.sqrt((dx * dx) + (dy * dy));

			//crash checker
			if (distance < player.halfWidth + tmpAsteroid.radius)
			{
				//game over
				Math.random() > 0.5 ? -1 : 1;
				uiRockName.html(asteroids[i].name !== null ? asteroids[i].name : "a No-Name");
				playGame = false;
				clearTimeout(scoreTimeout);
				uiStats.hide();
				uiComplete.show();

				$(window).unbind("keyup");
				$(window).unbind("keydown");
			}


			//asteroid collision
			asteroidCrash(tmpAsteroid);
			//draw asteroid
			drawAsteroid(tmpAsteroid);
			//asteroid name
			if (player.shooting)
			{
				asteroidName(tmpAsteroid, i);
			}
		}

		//stops movement when not pressing keys
		player.vx = 0;
		player.vy = 0;

		//move right, left, up, down and draw flame
		if (player.moveRight)
		{
			player.vx = playerSpeed;
			drawFlame(player, "right");
		}
		else if (player.moveLeft)
		{
			player.vx = -playerSpeed;
			drawFlame(player, "left");
		}
		if (player.moveUp)
		{
			player.vy = -playerSpeed;
			drawFlame(player, "up");
		}
		else if (player.moveDown)
		{
			player.vy = playerSpeed;
			drawFlame(player, "down");
		}

		//draw rocket
		drawRocket(player);

		player.x += player.vx;
		player.y += player.vy;

		//player movement borders -> left and right
		if (player.x - player.halfWidth < 20)
		{
			player.x = 20 + player.halfWidth;
		}
		else if (player.x + player.halfWidth > canvasWidth - 20)
		{
			player.x = canvasWidth - 20 - player.halfWidth;
		}

		//player movement borders -> Top and bottom
		if (player.y - player.halfHeight < 20)
		{
			player.y = 20 + player.halfHeight;
		}
		else if (player.y + player.halfHeight > canvasHeight - 20)
		{
			player.y = canvasHeight - 20 - player.halfHeight;
		}

		//increase asteroids
		while (asteroids.length < numAsteroids)
		{
			createAsteroidVariables(x, y, radius, vx, vy, mass, asteroids.length, true);
		}

		if (playGame)
		{
			//run the animation loop again in 33 milliseconds
			setTimeout(animate, 33);
		}
	}
	init();
});





