$(document).ready(function() {
	var canvas = $("#gameCanvas");
	var context = canvas.get(0).getContext("2d");
	
	//canvas dimensions
	var canvasWidth = canvas.width();
	var canvasHeight = canvas.height();
	
	//Game settings
	var playGame; //boolean flag
	var asteroids; //array that holds all the asteroids
	var numAsteroids; //number of active asteroids
	var player; //the player spaceship
	var score;	//the current score
	var scoreTimeout; //the timer object to increment score
	
	//keyboard keycodes
	var arrowUp = 38;
	var arrowRight = 39;
	var arrowDown = 40;
	
	var Asteriod = function(x,y,radius,vx){
		this.x = x;
		this.y = y;
		this.radius = radius;
		this.vx = vx;
	}
	
	var Player = function(x,y){
		this.x = x;
		this.y = y;
		this.width = 24;
		this.height = 24;
		this.halfWidth = this.width/2;
		this.halfHeight = this.height/2;
		
		this.vx = 0;
		this.vy = 0;
		
		this.moveRight = false;
		this.moveUp = false;
		this.moveDown = false;
		
		this.flameLength = 20;
	}
	
	//Game UI
	var ui = $("#gameUI");
	var uiIntro = $("#gameIntro");
	var uiStats = $("#gameStats");
	var uiComplete = $("#gameComplete");
	var uiPlay = $("#gamePlay");
	var uiReset = $(".gameReset");
	var uiScore = $(".gameScore");

	// reset and start the gameCanvas
	function startGame(){
		asteroids = new Array();
		numAsteroids = 10;
		score = 0;
		player = new Player(150, canvasHeight/2);
		
		//create asteroid variable values
		for (i=0;i<numAsteroids;i++)
		{
			var radius= 5+(Math.random()*10);
			var x= canvasWidth+radius+Math.floor(Math.random()*canvasWidth);
			var y= Math.floor(Math.random()*canvasHeight);
			var vx= -5-(Math.random()*5);
			
			asteroids.push(new Asteriod(x,y,radius,vx));
		}
		
		//key press listeners
		$(window).keydown(function(e){
			var keyCode = e.keyCode;
			
			//press a key to start the game
			if (!playGame){
				playGame = true;
				animate();
				timer();
			};
			
			//key -> direction
			if (keyCode == arrowRight){
				player.moveRight = true;
			}else if (keyCode == arrowUp){
				player.moveUp = true;
			}else if (keyCode == arrowDown){
				player.moveDown = true;
			}
		});
		
		//key release
		$(window).keyup(function(e){
			var keyCode = e.keyCode;
			
			if (keyCode == arrowRight){
				player.moveRight = false;
			}else if (keyCode == arrowUp){
				player.moveUp = false;
			}else if (keyCode == arrowDown){
				player.moveDown = false;
			}
		});
		
		//reset game stats
		uiScore.html("0");
		uiStats.show();
		
		// set up initial game settings
		playGame = false;
		
		//start the animation loop
		animate();
	};
	
	//inititialize the game environment
	function init() {
		uiStats.hide();
		uiComplete.hide();
		
		uiPlay.click(function(e) {
			e.preventDefault();
			uiIntro.hide();
			startGame();
		});
		
		uiReset.click(function(e) {
			e.preventDefault();
			uiComplete.hide();
			$(window).unbind("keyup");
			$(window).unbind("keydown");
			clearTimeout(scoreTimeout);
			startGame();
		});
	};
	
	function timer(){
		if (playGame) 
		{
			scoreTimeout = setTimeout(function() {
				uiScore.html(++score);
				if (score % 5 == 0)
				{
					numAsteroids += 5;
				}
				timer();
			},1000)
		}
	}
	
	//animation loop that does all the fun stuff
	function animate () {
		//clear
		context.clearRect(0,0,canvasWidth, canvasHeight);
		
		var asteroidsLength = asteroids.length;
		for (i=0;i<asteroidsLength;i++)
		{
			var tmpAsteroid = asteroids[i];
			
			tmpAsteroid.x += tmpAsteroid.vx;
			
			//asteroid off left move back to right
			if (tmpAsteroid.x+tmpAsteroid.radius<0)
			{
				tmpAsteroid.radius= 5+(Math.random()*10);
				tmpAsteroid.x= canvasWidth+tmpAsteroid.radius;
				tmpAsteroid.y= Math.floor(Math.random()*canvasHeight);
				tmpAsteroid.vx= -5-(Math.random()*5);
			}
			
			var dx = player.x - tmpAsteroid.x;
			var dy = player.y - tmpAsteroid.y;
			var distance = Math.sqrt((dx*dx)+(dy*dy));
			
			if (distance < player.halfWidth+tmpAsteroid.radius)
			{
				//game over
				playGame = false;
				clearTimeout(scoreTimeout);
				uiStats.hide();
				uiComplete.show();
				
				$(window).unbind("keyup");
				$(window).unbind("keydown");
			}
			
			//draw asteriod
			context.fillStyle="rgb(255,255,255)";
			context.beginPath();
			context.arc(tmpAsteroid.x,tmpAsteroid.y,tmpAsteroid.radius,0,Math.PI*2,true);
			context.closePath();
			context.fill();
		}
		
		//stops movement when not pressing keys
		player.vx = 0;
		player.vy = 0;
		
		//move right or left
		if(player.moveRight)
		{
			player.vx = 3;
		}else{
			player.vx = -3;
		}
		//move up
		if(player.moveUp)
		{
			player.vy = -3;
		}
		//move down
		if (player.moveDown)
		{
			player.vy = 3;
		}
		
		player.x += player.vx;
		player.y += player.vy;
		
		//player movement borders -> left and right
		if (player.x-player.halfWidth<20)
		{
			player.x = 20+player.halfWidth;
		}else if (player.x+player.halfWidth>canvasWidth-20)
		{
			player.x = canvasWidth-20-player.halfWidth;
		}
		
		//player movement borders -> Top and bottom
		if (player.y-player.halfHeight<20)
		{
			player.y = 20+player.halfHeight;
		}else if(player.y+player.halfHeight>canvasHeight-20)
		{
			player.y=canvasHeight-20-player.halfHeight;
		}
		
		//draw rocket flame
		if (player.moveRight)
		{
			context.save();
			context.translate(player.x-player.halfWidth,player.y);
			
			//flame flicker
			if (player.flameLength == 20){
				player.flameLength = 15;
			}else{
				player.flameLength = 20;
			};
			
			context.fillStyle = "orange";
			context.beginPath();
			context.moveTo(0,-5);
			context.lineTo(-player.flameLength,0);
			context.lineTo(0,5);
			context.closePath();
			context.fill();
			
			context.restore();
		}
		
		//draw rocket
		context.fillStyle = "rbg(255,0,0)";
		context.beginPath();
		context.moveTo(player.x+player.halfWidth,player.y);
		context.lineTo(player.x-player.halfWidth,player.y-player.halfHeight);
		context.lineTo(player.x-player.halfWidth,player.y+player.halfHeight);
		context.closePath();
		context.fill();
		
		while (asteroids.length < numAsteroids)
		{
			var radius = 5+(Math.random()*10);
			var x = Math.floor(Math.random()*canvasWidth)+canvasWidth+radius;
			var y = Math.floor(Math.random()*canvasHeight);
			var vx = -5-(Math.random()*5);
			
			asteroids.push(new Asteriod(x,y,radius,vx));
		}
		
		if (playGame){
			//run the animation loop again in 33 milliseconds
			setTimeout(animate, 33);
		}
	};
	init();
});





