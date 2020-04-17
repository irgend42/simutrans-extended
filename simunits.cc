/*
 * simunits.cc
 *
 * Created on: 24.02.2013
 *     Author: Bernd Gabriel
 *
 * This file is part of the Simutrans project under the artistic license.
 * (see license.txt)
 */

#include "simunits.h"

const float32e8_t legacy_kmh2ms((uint32) 10, (uint32) 36);
const float32e8_t legacy_ms2kmh((uint32) 36, (uint32) 10);

/**
 * Conversion between simutrans speed and m/s
 */

// scale to convert between simutrans speed and m/s
const float32e8_t legacy_simspeed2ms((uint32) 10 * VEHICLE_SPEED_FACTOR, (uint32) 36 * 64);
const float32e8_t legacy_ms2simspeed((uint32) 36 * 64, (uint32) 10 * VEHICLE_SPEED_FACTOR);

/**
 * Conversion between simutrans steps and meters
 */
// scale to convert between simutrans steps and meters
//const float32e8_t yards2m((uint32) 10 * VEHICLE_SPEED_FACTOR, (uint32) 36 * 1024 * DT_TIME_FACTOR);
//const float32e8_t m2yards((uint32) 36 * 1024 * DT_TIME_FACTOR, (uint32) 10 * VEHICLE_SPEED_FACTOR);
const float32e8_t legacy_steps2yards((uint32)1 << YARDS_PER_VEHICLE_STEP_SHIFT);

const sint32 SPEED_MIN = kmh_to_speed(KMH_MIN);
const float32e8_t LEGACY_V_MIN = legacy_kmh2ms * KMH_MIN;

uint16 meters_per_tile2;

float32e8_t seconds_per_tick;

float32e8_t meters_per_step;
float32e8_t steps_per_meter;

void simunits_init(uint16 meters_per_tile){
    ::meters_per_tile2=meters_per_tile;

    seconds_per_tick = ticks_to_fseconds(1, meters_per_tile2);

    steps_per_meter = meters_to_steps(1, meters_per_tile);
    meters_per_step = steps_to_meters(1, meters_per_tile);
}