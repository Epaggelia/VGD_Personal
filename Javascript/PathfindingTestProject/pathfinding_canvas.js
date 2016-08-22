var canvas = null;
var ctx = null;
var spritesheet = null;
var spritesheetLoaded = false;

var world = [[]];

// size in the world in sprite tiles
var worldWidth = 480;
var worldHeight = 320;

// size of a tile in pixels
var tileWidth = 1;
var tileHeight = 1;

// start and end of path
var pathStart = [worldWidth, worldHeight];
var pathEnd = [0, 0];
var currentPath = [];

// the html page is ready
function onload()
{
	console.log('Page loaded.');
	canvas = document.getElementById('gameCanvas');
	canvas.width = worldWidth * tileWidth;
	canvas.height = worldHeight * tileHeight;
	canvas.addEventListener("click", canvasClick); 
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

function loaded()
{
	console.log('Spritesheet loaded.');
	spritesheetLoaded = true;
	createWorld("level_one");
}

function redraw()
{
	if (!spritesheetLoaded) // only redraw() if spritesheet is loaded
		return;

	console.log('redrawing...');

	var spriteNum = 0;

	// clear the screen
	ctx.fillStyle = '#000000';
	ctx.fillRect(0, 0, canvas.width, canvas.height);

	drawLand ();
	
	console.log('Current path length: ' + currentPath.length);
	drawPath();
}

function canvasClick(e)
{
	var x;
	var y;

	if (e.pageX != undefined && e.pageY != undefined)
	{
		x = e.pageX; //set x to the mouses distance from the left edge of the browser window
		y = e.pageY; //set y to the mouses distance from the left edge of the browser
	} 

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
	currentPath = findPath(world, pathStart, pathEnd,true,true);
	redraw();
}

// start running immediately
onload();