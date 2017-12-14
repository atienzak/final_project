# Defend the Den

My intended final project for PIC 10C would be a game similar to Plants vs. Zombies, in which a player can place defenders along a grid-like structure to prevent monsters from destroying the den. Instead of having different levels, the rate of 
monsters coming along would increase as time goes by, with the objective of the game being to hold out as long as the player can.

I used QT for the GUI of the game, and used Qt's Graphics View Framework to make the game look better.

Memory Management:
* try-catch method - I used try-catch method when initializing variables on the heap
* copy and swap idiom - this idiom is used for copy-assignment operators
* RAII - I made sure to set up proper parents of items in order to handle memory efficiently

Needed Improvements:
* Paint Events Lag - the game currently lags whenever resizing the window or moving the mouse. I think this happens due paint events being called multiple times; however, I was not able to fix this problem, as I cannot point out where the paint events are being called.
* Optimization - Due to the way I designed the game initially, I had to include some functions that call other functions as a relay. This is not as efficient as I would like, as it seems like there are two functions for different classes that only do one thing. There are also containers the contain a lot of pointer variables, so I had to make sure that I set those pointers to null manually. 
* Timer - the main "animations" of the game is due to the underlying timer within the Scene that advances the items in the game. This means that things are moving using a set-position function. It would be better, it seems, if I used Open GL to make the game much smoother. This also makes having a proper game logic difficult, as things are constantly moving,
* Other - it would be great to have more types of shooters and other miscellanous graphics in order to improve the game's look and game design. 

Why I didn't use:
* Smart Pointers - whenever things are colliding, for example a bullet to a zombie, I had to delete those items manually.
* Lambda Functions, Templates, etc. - I did not find the need to use these; maybe in the future, when I intend to improve my game.

### Overall Impressions

It took me way longer to learn Qt than I have anticipated; however, though the learning curve was steep, I was able to get comfortable with it after a few weeks even though it took time away from some of the stuff I wanted to include with my game. Overall, this final project was definitely enjoyable, and I am glad to have learned a new skill through Qt, as I have always wanted to make a GUI application. 
