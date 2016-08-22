// A* Pathfinding for HTML5 Canvas Tutorial
// by Christer (McFunkypants) Kaitila
// http://www.mcfunkypants.com
// http://twitter.com/McFunkypants

// Based on Edsger Dijkstra's 1959 algorithm and work by:
// Andrea Giammarchi, Alessandro Crugnola, Jeroen Beckers,
// Peter Hart, Nils Nilsson, Bertram Raphael

// Permission is granted to use this source in any
// way you like, commercial or otherwise. Enjoy!

// the game's canvas element
var canvas = null;
// the canvas 2d context
var ctx = null;
// an image containing all sprites
var spritesheet = null;
// true when the spritesheet has been downloaded
var spritesheetLoaded = false;

// the world grid: a 2d array of tiles
var world = [[]];

// size in the world in sprite tiles
var worldWidth = 16;
var worldHeight = 16;

// size of a tile in pixels
var tileWidth = 32;
var tileHeight = 32;

// start and end of path
var pathStart = [worldWidth, worldHeight];
var pathEnd = [0, 0];
var currentPath = [];

// ensure that concole.log doesn't cause errors
//// checks to see if console is loaded properly and if not, makes it
if (typeof console == "undefined")
	var console = {log: function () {}};

// the html page is ready
function onload()
{
	console.log('Page loaded.');
	canvas = document.getElementById('gameCanvas');
	canvas.width = worldWidth * tileWidth;
	canvas.height = worldHeight * tileHeight;
	canvas.addEventListener("click", canvasClick); 
	//// checks if canvas variable was made
	if (!canvas)
		alert('Blah!');
	ctx = canvas.getContext("2d");
	//// checks if ctx variable was made
	if (!ctx)
		alert('Hmm!');
	spritesheet = new Image();
	spritesheet.src = 'spritesheet.png';
	spritesheet.onload = loaded;
}

/////////////////////////////////////////////////////////////////////////
// the spritesheet is ready
function loaded()
{
	console.log('Spritesheet loaded.');
	spritesheetLoaded = true;
	createWorld();
}

/////////////////////////////////////////////////////////////////////////
//pulled createWorld() function from here and moved to own file
/////////////////////////////////////////////////////////////////////////
function redraw()
{
	if (!spritesheetLoaded) // only redraw() if spritesheet is loaded
		return;

	console.log('redrawing...');

	var spriteNum = 0;

	// clear the screen
	ctx.fillStyle = '#000000';
	ctx.fillRect(0, 0, canvas.width, canvas.height);

/////////////////////////////////////////////////////////////////////////
//pulled land drawing logic and made function for it in Redraw.js
/////////////////////////////////////////////////////////////////////////
	drawLand ();
	
/////////////////////////////////////////////////////////////////////////
//pulled path drawing logic and made function for it in Redraw.js
/////////////////////////////////////////////////////////////////////////
	console.log('Current path length: ' + currentPath.length);
	drawPath();
}

/////////////////////////////////////////////////////////////////////////
// handle click events on the canvas
/////////////////////////////////////////////////////////////////////////
function canvasClick(e)
{
	var x;
	var y;

	// grab html page coords
	if (e.pageX != undefined && e.pageY != undefined)
	{
		x = e.pageX; //set x to the mouses distance from the left edge of the browser window
		y = e.pageY; //set y to the mouses distance from the left edge of the browser
	} 
	//alternate way of getting x,y if they are for some reason undefined
	/* 
	else
	{
		x = e.clientX + document.body.scrollLeft +
				document.documentElement.scrollLeft;
		y = e.clientY + document.body.scrollTop +
				document.documentElement.scrollTop;
	}
	*/

	// make them relative to the canvas only
	x -= canvas.offsetLeft; // subtract distance between left edge of browser and canvas
	y -= canvas.offsetTop; // subtract distance between top edge of browser and canvas

	// return tile x,y that we clicked
	var cell =
			[
				Math.floor(x / tileWidth),
				Math.floor(y / tileHeight)
			];

	// now we know what tile we clicked
	console.log('we clicked tile ' + cell[0] + ',' + cell[1]);

	pathStart = pathEnd;	// set start to previous end point
	pathEnd = cell;			// set new end point where clicked

	// calculate path
	currentPath = findPath(world, pathStart, pathEnd,true);
	redraw();
}

// start running immediately
onload();