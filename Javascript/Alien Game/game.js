function gameLogic() {
	var cannon = document.querySelector("#cannon");
	var alien = document.querySelector("#alien");
	var missile = document.querySelector("#missile");
	var explosion = document.querySelector("#explosion");
	var inputX = document.querySelector("#inputX");
	var inputY = document.querySelector("#inputY");
	var output = document.querySelector("#output");
	var button = document.querySelector("button");

	var alienX = Math.floor((Math.random()*280));
	var alienY = 20;
		alien.style.left = alienX + "px";
	var guessX = 0;
	var guessY = 0;
	var shotsRemaining = 8;
	var shotMade = 0;
	var gameState = "";
	var gameWon = false;

	button.addEventListener("click", clickHandler);

	function clickHandler() {
		validateInput();
	}

	function validateInput() {
		guessX = parseInt(inputX.value);
		guessY = parseInt(inputY.value);

		if (isNaN(guessX) || isNaN(guessY))
		{
			output.innerHTML = "Please enter a valid number.";
		} else
		{
			if (guessX < 0 || guessY < 0 || guessX > 300 || guessY > 300)
			{
				output.innerHTML = "Please enter a number in the range.";
			} else {
				playGame();
			}
		}
	}
	function playGame() {
		shotsRemaining -= 1;
		shotMade += 1;
		gameState = "<br>Shots: " + shotMade + "<br>Remaining: " + shotsRemaining;

		if (guessX +9 >= alienX && guessX <= alienX + 20) {
			if (guessY + 9 >= alienY && guessY <= alienY + 20) {
				gameWon = true;
				endGame();
			} else {
				output.innerHTML = "Miss! " + gameState;
			}
		} else {
			output.innerHTML = "Miss! " + gameState;
		}

		if (shotsRemaining < 1)
		{
			endGame();
		}
		if (!gameWon) {
			alienY += 30;
			alienX = Math.floor((Math.random()*280));
					console.log(alienX,alienY);
		}
		updateGraphics();
	}

	function endGame() {
		if (gameWon == true) {
			output.innerHTML = "Hit! You saved the earth!<br>" +
					"It only took you " + shotMade + " shots.";
		} else {
			output.innerHTML = "You lost!<br>" + "The earth was destroyed!";
		}

		button.removeEventListener("click", clickHandler);
		button.disabled = true;
	}

	function updateGraphics() {
		missile.style.left = guessX + "px";
		missile.style.top = guessY + "px";
		cannon.style.left = guessX -5 + "px";
		alien.style.left = alienX + "px";
		alien.style.top = alienY + "px";

		if (gameWon == true) {
			explosion.style.display = "block";
			explosion.style.left = alienX + "px";
			explosion.style.top = alienY + "px";

			alien.style.display = "none";
			missile.style.display = "none";
		}
	}
}