

$(document).ready(function(){

	var canvas = $("#myCanvas");
	var context = canvas.get(0).getContext("2d");
	
	var array1 = [0];
	var array2 = [0];
	
	function resizeCanvas(){
		canvas.attr("width", $(window).get(0).innerWidth);
		canvas.attr("height", $(window).get(0).innerHeight);
	
		for (i=0;i<(canvas.width()/(numA*2))+1;i++)
		{
			array1[i]=(i-1)*(numA*2);
		}
		
		for (i=0;i<(canvas.height()/(numA*2))+1;i++)
		{
			array2[i]=(i-1)*(numA*2);
		}
	}
	
	$(window).resize(resizeCanvas);

	var numA,numB,numC,numD;
		numA = 50;
		numB = 0;
		numC = 0;
		numD = 0;
		
	
	
		
	function draw() {
		setTimeout(draw,33)
			resizeCanvas();
			context.fillStyle="white";
			context.fillRect(0,0,canvas.width(),canvas.height());
			context.fillStyle="black";
			
			numD = 0;
			
		for (i=-(numA*2);i<canvas.width();i+=(numA)*2)
		{
			numC = 0;
			for (r=-(numA*2);r<canvas.height();r+=(numA)*2)
			{
				context.fillRect(array1[numD]+numB,array2[numC]+numB,numA,numA);
				context.fillRect((array1[numD]+numB)+numA,(array2[numC]+numB)+numA,numA,numA);
				numC++;
			}
			numD++;
		}
		if (numB >= (numA*2))
		{
			numB = 0;
		}
		else
		{
			numB++;
		}
	};
	
	draw();

});