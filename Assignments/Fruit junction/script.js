let score = 0;
let gameInterval;
const fruits = ['apple.png', 'banana.png', 'orange.png', 'watermelon.png'];
const gameArea = document.getElementById('gameArea');
const startButton = document.getElementById('startButton');

function spawnFruit() {
    const fruitIndex = Math.floor(Math.random() * fruits.length);
    const fruit = document.createElement('img');
    fruit.src = fruits[fruitIndex];
    fruit.className = 'fruit';
    fruit.style.left = '0px';
    fruit.style.top = Math.random() * (gameArea.clientHeight - 80) + 'px'; // Random vertical position

    gameArea.appendChild(fruit);

    // Animate the fruit moving across the screen
    let position = 0;
    const interval = setInterval(() => {
        position += 5; // Move the fruit to the right
        fruit.style.left = position + 'px';

        // Check if the fruit has moved out of the game area
        if (position > gameArea.clientWidth) {
            clearInterval(interval);
            gameArea.removeChild(fruit); // Remove the fruit if it goes out of bounds
        }
    }, 100);

    // Add click event to cut the fruit
    fruit.onclick = function() {
        if (!fruit.classList.contains('cut')) {
            fruit.classList.add('cut');
            score++;
            document.getElementById('score').innerText = `Score: ${score}`;
            clearInterval(interval); // Stop the fruit from moving
            setTimeout(() => gameArea.removeChild(fruit), 500); // Remove the fruit after a short delay
        }
    };
}

function startGame() {
    score = 0;
    document.getElementById('score').innerText = `Score: ${score}`;
    gameArea.innerHTML = ''; // Clear the game area
    gameInterval = setInterval(spawnFruit, 1000); // Spawn a new fruit every second
    startButton.disabled = true; // Disable the start button
}

startButton.onclick = startGame;