function gameLogic() {
    //Game variables
    var ceiling = 99;
    var mysteryNumber = Math.floor(Math.random() * ceiling + 1);
    var playerGuess = 0;
    var guessesRemaining = 10;
    var guessesMade = 0;
    var gameState = "";
    var gameWon = false;

    var input = document.querySelector("#inputField");
    var output = document.querySelector("#outputField");
    var button = document.querySelector("button");

    output.innerHTML = "Pick a number between 0 and 99. <br> <br>"

    button.addEventListener("click", clickHandler, false);

    function clickHandler() {
        validateInput();
    }

    function validateInput() {
        playerGuess = parseInt(input.value);

        if (isNaN(playerGuess) == true)
        {
            output.innerHTML = "Please enter a number."
        } else {
            if (playerGuess < 0 || playerGuess > ceiling)
            {
                output.innerHTML = "Number not in range."
            } else
            {
                playGame();
            }
        }
    }

    function playGame() {
        guessesRemaining -= 1;
        guessesMade += 1;
        gameState = "<br> Guesses: " + guessesMade + "<br> Remaining: " + guessesRemaining;

        playerGuess = parseInt(input.value);

        if (playerGuess > mysteryNumber)
        {
            output.innerHTML = "Too High." + gameState;
        } else if (playerGuess < mysteryNumber)
        {
            output.innerHTML = "Too Low." + gameState;
        } else if (playerGuess == mysteryNumber)
        {
            gameWon = true;
        }

        if (guessesRemaining < 1 || playerGuess == mysteryNumber)
        {
            endGame();
        }
    }

    function endGame() {
        if (gameWon)
        {
            output.innerHTML = "The number was " + mysteryNumber + ".<br>" + "You took " + guessesMade + " guesses.<br>";
        } else
        {
            output.innerHTML = "No more guesses left.<br>The number was " + mysteryNumber + ".<br>";
        }

        button.removeEventListener("click", clickHandler, false);
        button.disabled = true;

        input.disabled = true;
    }
}