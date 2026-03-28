#pragma once

/// Points awarded to other players when one player dies.
const int ALIVE_POINTS = 1;
/// Points per controlled hill. This quantity is subtracted when player loses a
/// hill.
const int POINTS_PER_HILL = 1;
/// Points awarded to player that destroyed a hill.
const int RAZING_POINTS = 2;

/// Maximum number of unclaimed food on map.
const int MAX_FOOD_COUNT = 20;
/// Maximum number of turns before game end.
const int MAX_TURN_COUNT = 300;

const int ANT_BATTLE_RADIUS2 = 5;
const int ANT_GATHER_RADIUS2 = 1;
const int ANT_MOVE_RADIUS2 = 1;
