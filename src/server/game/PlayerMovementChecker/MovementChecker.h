/*
 * Copyright � 2012 SymphonyArt <http://symphonyart.com/>
 *
 * Copyright (C) 2010 - 2012 Myth Project <http://mythprojectnetwork.blogspot.com/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TRINITY_MOVEMENTCHECKER_H
#define TRINITY_MOVEMENTCHECKER_H

#include "WorldSession.h"
#include "Player.h"
#include "Vehicle.h"

class PlayerMovementChecker
{
    public:
        PlayerMovementChecker(Player *player) : _player(player)
        {
            _movementInfo = NULL;
            _opcode = 0;
            _lastServerTime = 0;
            _currServerTime = 0;
            _lastClientTime = 0;
            _timediff = 0;
            _vehicle = NULL;

            _lastXCoord = 0.0f;
            _lastYCoord = 0.0f;
            _lastZCoord = 0.0f;
            _lastMovementZCoord = 0.0f;
            _mapZ = 0.0f;
            _floorZ = 0.0f;
            _distance2D = 0.0f;
            _distance3D = 0.0f;
            _alreadyJumped = false;
            _currSpeed = 0.0f;
            _lastSpeed = 0.0f;
            _moverSize = 0;
            _speedChanged = false;
            _lastFallTime = 0;
            _hasFlyingFlags = false;
            _justWasInAir = false;
            _justCharged = false;
            _lastWaterwalkTime = 0;
            _inAirCheck = false;
            _isAboveFloor = false;
            _moverHeight = 0.0f;
            _justTurn = false;
            _isInWater = false;
            _lastInWaterTime = 0;
            _lastFeatherFallTime = 0;
            _lastFlyingTime = 0;
            _latency = 0;
            _justWasInWater = false;
        }

        ~PlayerMovementChecker() { }

        void prepare(MovementInfo *movementInfo, uint16 opcode);
        bool canMove();
        void doMovementCorrection();
    private:
        Player *_player;
        Unit *_mover;
        MovementInfo *_movementInfo;
        uint16 _opcode;

        uint32 _lastServerTime;
        uint32 _currServerTime;
        uint32 _timediff;
        uint32 _lastClientTime;
        uint32 _lastFallTime;
        uint32 _lastFlyingTime;
        uint32 _lastWaterwalkTime;
        uint32 _lastFeatherFallTime;
        uint32 _lastInWaterTime;
        uint32 _latency;
        Unit *_vehicle;

        uint32 _moverSize;

        float _lastXCoord, _lastYCoord, _lastZCoord, _lastMovementZCoord,
            _mapZ, _floorZ, _distance2D, _distance3D, _currSpeed, _lastSpeed,
            _moverHeight;

        bool _alreadyJumped;
        bool _speedChanged;
        bool _hasFlyingFlags;
        bool _justWasInAir;
        bool _justCharged;
        bool _inAirCheck;
        bool _isAboveFloor;
        bool _justTurn;
        bool _isInWater;
        bool _justWasInWater;

        bool isFlyingOk();
        bool isPlaneOk();
        bool isJumpOk();
        bool isFeatherFallOk();
        bool isWaterWalkOk();
        bool isSpeedOk();
        bool isZCoordOk();
        bool isInAir();

        UnitMoveType GetMovementType();
};

#endif