<div dir="rtl" lang="he">

# War Game

This is simple game thar represent soldiers and board.
There is two players which play against the other.
Each soldier has specific abbility, for example: paramedic can recover his friends.
Furthermore every soldier has a commander, and when the commander attak all the same soldier type of the commander is attack to.
Each soldier has life and power hence soldier is die when his life is less then or equal to zero.
Each soldier start with some points of health and power.
The first player that lost all his soldiers - lose.


## List of all the soldiers and their abbility

* FootSoldier - Walk to any direction he wants and shoot to the nearest enemy(if there is multiple choose randomize).
* FootCommander - Same as FootSoldier with the abbility that when he attack all the subordinates attacks also.
* Sniper - Walk to any direction he wants and shoot to the enemy who have the most HP(if there is multiple choose randomize).
* SniperCommander - Same as Sniper with the abbility that when he attack all the subordinates attacks also.
* Paramedic - Walk to any direction he wants,NOT shootat all and repair HP damage for all his friend beside him in range of one step.
* ParamedicCommander - Same as Paramedic with the abbility that when he repair all the subordinates repairs also.

## Soldiers settings

* FootSoldier: initial health points=100, damage per activity=10.
* FootCommander: initial health points=150, damage per activity=20.
* Sniper: initial health points=100, damage per activity=50.
* SniperCommander: initial health points=120, damage per activity=100.
* Paramedic: initial health points=100, health per activity=full.
* ParamedicCommander: initial health points=200, health per activity=full.

## Classes

Board.hpp - represent the functionality of the board.
DemoGame - is illustration of how the game should work.


## Tests
There is use of doctest for testing the game, it may be helpful for better understanding the role of the game.


