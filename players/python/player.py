#!/bin/env python
import sys
from typing import List
from data import World, Move, Person, World, Map, Shade, Tombstone, Point
from game import Game, PlayerInterface


class Player(PlayerInterface):
    @staticmethod
    def log(*args):
        print(*args, file=sys.stderr)

    def init(self, world: World) -> None:
        Player.log("init")
        pass

    def get_turn(self, world: World) -> List[Move]:
        moves = []
        for id, ant in world.alive_shades.items():
            for ngb in ant.position.get_neighbouring():
                if world.map.can_move_to(ngb):
                    moves.append(Move(id, ngb))
                    break
        return moves

if __name__ == "__main__":
    game = Game(Player())
    game.run()
