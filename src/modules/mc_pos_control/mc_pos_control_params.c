/****************************************************************************
 *
 *   Copyright (c) 2013-2016 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/**
 * @file mc_pos_control_params.c
 * Multicopter position controller parameters.
 *
 * @author Anton Babushkin <anton@px4.io>
 */

/**
 * Minimum thrust in auto thrust control
 *
 * It's recommended to set it > 0 to avoid free fall with zero thrust.
 *
 * @unit norm
 * @min 0.05
 * @max 1.0
 * @decimal 2
 * @increment 0.01
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_THR_MIN, 0.12f);

/**
 * Hover thrust
 *
 * Vertical thrust required to hover.
 * This value is mapped to center stick for manual throttle control.
 * With this value set to the thrust required to hover, transition
 * from manual to Altitude or Position mode while hovering will occur with the
 * throttle stick near center, which is then interpreted as (near)
 * zero demand for vertical speed.
 *
 * This parameter is also important for the landing detection to work correctly.
 *
 * @unit norm
 * @min 0.1
 * @max 0.8
 * @decimal 2
 * @increment 0.01
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_THR_HOVER, 0.5f);

/**
 * Hover thrust source selector
 *
 * Set false to use the fixed parameter MPC_THR_HOVER
 * Set true to use the value computed by the hover thrust estimator
 *
 * @boolean
 * @group Multicopter Position Control
 */
PARAM_DEFINE_INT32(MPC_USE_HTE, 1);

/**
 * Thrust curve in Manual Mode
 *
 * This parameter defines how the throttle stick input is mapped to commanded thrust
 * in Manual/Stabilized flight mode.
 *
 * In case the default is used ('Rescale to hover thrust'), the stick input is linearly
 * rescaled, such that a centered stick corresponds to the hover throttle (see MPC_THR_HOVER).
 *
 * Select 'No Rescale' to directly map the stick 1:1 to the output. This can be useful
 * in case the hover thrust is very low and the default would lead to too much distortion
 * (e.g. if hover thrust is set to 20%, 80% of the upper thrust range is squeezed into the
 * upper half of the stick range).
 *
 * Note: In case MPC_THR_HOVER is set to 50%, the modes 0 and 1 are the same.
 *
 * @value 0 Rescale to hover thrust
 * @value 1 No Rescale
 * @group Multicopter Position Control
 */
PARAM_DEFINE_INT32(MPC_THR_CURVE, 0);

/**
 * Maximum thrust in auto thrust control
 *
 * Limit max allowed thrust
 *
 * @unit norm
 * @min 0.0
 * @max 1.0
 * @decimal 2
 * @increment 0.01
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_THR_MAX, 1.0f);

/**
 * Minimum manual thrust
 *
 * Minimum vertical thrust. It's recommended to set it > 0 to avoid free fall with zero thrust.
 * With MC_AIRMODE set to 1, this can safely be set to 0.
 *
 * @unit norm
 * @min 0.0
 * @max 1.0
 * @decimal 2
 * @increment 0.01
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_MANTHR_MIN, 0.08f);

/**
 * Proportional gain for vertical position error
 *
 * @min 0.0
 * @max 1.5
 * @decimal 2
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_Z_P, 1.0f);

/**
 * Proportional gain for vertical velocity error
 *
 * defined as correction acceleration in m/s^2 per m/s velocity error
 *
 * @min 2.0
 * @max 8.0
 * @decimal 2
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_Z_VEL_P_ACC, 4.0f);

/**
 * Integral gain for vertical velocity error
 *
 * defined as correction acceleration in m/s^2 per m velocity integral
 *
 * Non zero value allows hovering thrust estimation on stabilized or autonomous takeoff.
 *
 * @min 0.2
 * @max 2.0
 * @decimal 3
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_Z_VEL_I_ACC, 2.0f);

/**
 * Differential gain for vertical velocity error
 *
 * defined as correction acceleration in m/s^2 per m/s^2 velocity derivative
 *
 * @min 0.0
 * @max 2.0
 * @decimal 3
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_Z_VEL_D_ACC, 0.0f);

/**
 * Maximum vertical ascent velocity
 *
 * Maximum vertical velocity in AUTO mode and endpoint for stabilized modes (ALTCTRL, POSCTRL).
 *
 * @unit m/s
 * @min 0.5
 * @max 8.0
 * @decimal 1
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_Z_VEL_MAX_UP, 3.0f);

/**
 * Maximum vertical descent velocity
 *
 * Maximum vertical velocity in AUTO mode and endpoint for stabilized modes (ALTCTRL, POSCTRL).
 *
 * @unit m/s
 * @min 0.5
 * @max 4.0
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_Z_VEL_MAX_DN, 1.0f);

/**
 * Proportional gain for horizontal position error
 *
 * @min 0.0
 * @max 2.0
 * @decimal 2
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_XY_P, 0.95f);

/**
 * Proportional gain for horizontal velocity error
 *
 * defined as correction acceleration in m/s^2 per m/s velocity error
 *
 * @min 1.2
 * @max 3.0
 * @decimal 2
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_XY_VEL_P_ACC, 1.8f);

/**
 * Integral gain for horizontal velocity error
 *
 * defined as correction acceleration in m/s^2 per m velocity integral
 * Non-zero value allows to eliminate steady state errors in the presence of disturbances like wind.
 *
 * @min 0.0
 * @max 60.0
 * @decimal 3
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_XY_VEL_I_ACC, 0.4f);

/**
 * Differential gain for horizontal velocity error. Small values help reduce fast oscillations. If value is too big oscillations will appear again.
 *
 * defined as correction acceleration in m/s^2 per m/s^2 velocity derivative
 *
 * @min 0.1
 * @max 2.0
 * @decimal 3
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_XY_VEL_D_ACC, 0.2f);

/**
 * Maximum horizontal velocity in mission
 *
 * Normal horizontal velocity in AUTO modes (includes
 * also RTL / hold / etc.) and endpoint for
 * position stabilized mode (POSCTRL).
 *
 * @unit m/s
 * @min 3.0
 * @max 20.0
 * @increment 1
 * @decimal 2
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_XY_CRUISE, 5.0f);

/**
 * Proportional gain for horizontal trajectory position error
 *
 * @min 0.1
 * @max 1.0
 * @decimal 1
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_XY_TRAJ_P, 0.5f);

/**
 * Maximum horizontal velocity setpoint for manual controlled mode
 * If velocity setpoint larger than MPC_XY_VEL_MAX is set, then
 * the setpoint will be capped to MPC_XY_VEL_MAX
 *
 * @unit m/s
 * @min 0.0
 * @max 20.0
 * @increment 1
 * @decimal 2
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_VEL_MANUAL, 10.0f);

/**
 * Maximum horizontal velocity
 *
 * Maximum horizontal velocity in AUTO mode. If higher speeds
 * are commanded in a mission they will be capped to this velocity.
 *
 * @unit m/s
 * @min 0.0
 * @max 20.0
 * @increment 1
 * @decimal 2
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_XY_VEL_MAX, 12.0f);

/**
 * Maximum tilt angle in air
 *
 * Limits maximum tilt in AUTO and POSCTRL modes during flight.
 *
 * @unit deg
 * @min 20.0
 * @max 89.0
 * @decimal 1
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_TILTMAX_AIR, 45.0f);

/**
 * Maximum tilt during landing
 *
 * Limits maximum tilt angle on landing.
 *
 * @unit deg
 * @min 10.0
 * @max 89.0
 * @decimal 1
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_TILTMAX_LND, 12.0f);

/**
 * Landing descend rate
 *
 * @unit m/s
 * @min 0.6
 * @decimal 1
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_LAND_SPEED, 0.7f);

/**
 * Maximum horizontal position mode velocity when close to ground/home altitude
 * Set the value higher than the otherwise expected maximum to disable any slowdown.
 *
 * @unit m/s
 * @min 0
 * @decimal 1
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_LAND_VEL_XY, 10.0f);

/**
 * Enable user assisted descent speed for autonomous land routine.
 *
 * When enabled, descent speed will be:
 * stick full up - 0
 * stick centered - MPC_LAND_SPEED
 * stick full down - 2 * MPC_LAND_SPEED
 *
 * @min 0
 * @max 1
 * @value 0 Fixed descent speed of MPC_LAND_SPEED
 * @value 1 User assisted descent speed
 */
PARAM_DEFINE_INT32(MPC_LAND_RC_HELP, 0);

/**
 * Takeoff climb rate
 *
 * @unit m/s
 * @min 1
 * @max 5
 * @decimal 2
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_TKO_SPEED, 1.5f);

/**
 * Maximal tilt angle in manual or altitude mode
 *
 * @unit deg
 * @min 0.0
 * @max 90.0
 * @decimal 1
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_MAN_TILT_MAX, 35.0f);

/**
 * Max manual yaw rate
 *
 * @unit deg/s
 * @min 0.0
 * @max 400
 * @decimal 1
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_MAN_Y_MAX, 150.0f);

/**
 * Manual yaw rate input filter time constant
 * Setting this parameter to 0 disables the filter
 *
 * @unit s
 * @min 0.0
 * @max 5.0
 * @decimal 2
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_MAN_Y_TAU, 0.08f);

/**
 * Deadzone of sticks where position hold is enabled
 *
 * @min 0.0
 * @max 1.0
 * @decimal 2
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_HOLD_DZ, 0.1f);

/**
 * Maximum horizontal velocity for which position hold is enabled (use 0 to disable check)
 *
 * @unit m/s
 * @min 0.0
 * @max 3.0
 * @decimal 2
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_HOLD_MAX_XY, 0.8f);

/**
 * Maximum vertical velocity for which position hold is enabled (use 0 to disable check)
 *
 * @unit m/s
 * @min 0.0
 * @max 3.0
 * @decimal 2
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_HOLD_MAX_Z, 0.6f);

/**
 * Low pass filter cut freq. for numerical velocity derivative
 *
 * @unit Hz
 * @min 0.0
 * @max 10
 * @decimal 2
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_VELD_LP, 5.0f);

/**
 * Maximum horizontal acceleration for auto mode and for manual mode
 *
 * Maximum deceleration for MPC_POS_MODE 1. Maximum acceleration and deceleration for MPC_POS_MODE 3.
 *
 * @unit m/s/s
 * @min 0.1
 * @max 15.0
 * @increment 1
 * @decimal 2
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_ACC_HOR_MAX, 5.0f);

/**
 * Acceleration for auto and for manual
 *
 * Note: In manual, this parameter is only used in MPC_POS_MODE 1.
 *
 * @unit m/s/s
 * @min 2.0
 * @max 15.0
 * @increment 1
 * @decimal 2
 * @group Multicopter Position Control
 */

PARAM_DEFINE_FLOAT(MPC_ACC_HOR, 3.0f);

/**
 * Slow horizontal manual deceleration for manual mode
 *
 * Note: This is only used when MPC_POS_MODE is set to 1.
 *
 * @unit m/s/s
 * @min 0.5
 * @max 10.0
 * @increment 1
 * @decimal 2
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_DEC_HOR_SLOW, 5.0f);

/**
 * Maximum vertical acceleration in velocity controlled modes upward
 *
 * @unit m/s/s
 * @min 2.0
 * @max 15.0
 * @increment 1
 * @decimal 2
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_ACC_UP_MAX, 4.0f);

/**
 * Maximum vertical acceleration in velocity controlled modes down
 *
 * @unit m/s/s
 * @min 2.0
 * @max 15.0
 * @increment 1
 * @decimal 2
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_ACC_DOWN_MAX, 3.0f);

/**
 * Maximum jerk limit
 *
 * Limit the maximum jerk of the vehicle (how fast the acceleration can change).
 * A lower value leads to smoother vehicle motions, but it also limits its
 * agility (how fast it can change directions or break).
 *
 * Setting this to the maximum value essentially disables the limit.
 *
 * Note: This is only used when MPC_POS_MODE is set to a smoothing mode 1 or 3.
 *
 * @unit m/s/s/s
 * @min 0.5
 * @max 500.0
 * @increment 1
 * @decimal 2
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_JERK_MAX, 8.0f);

/**
 * Velocity-based jerk limit
 *
 * If this is not zero, a velocity-based maximum jerk limit is used: the applied
 * jerk limit linearly increases with the vehicle's velocity between
 * MPC_JERK_MIN (zero velocity) and MPC_JERK_MAX (maximum velocity).
 *
 * This means that the vehicle's motions are smooth for low velocities, but
 * still allows fast direction changes or breaking at higher velocities.
 *
 * Set this to zero to use a fixed maximum jerk limit (MPC_JERK_MAX).
 *
 * Note: This is only used when MPC_POS_MODE is set to 1.
 *
 * @unit m/s/s/s
 * @min 0
 * @max 30.0
 * @increment 1
 * @decimal 2
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_JERK_MIN, 8.0f);

/**
 * Jerk limit in auto mode
 *
 * Limit the maximum jerk of the vehicle (how fast the acceleration can change).
 * A lower value leads to smoother vehicle motions, but it also limits its
 * agility.
 *
 * @unit m/s/s/s
 * @min 1.0
 * @max 80.0
 * @increment 1
 * @decimal 1
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_JERK_AUTO, 4.0f);

/**
 * Altitude control mode.
 *
 * Set to 0 to control height relative to the earth frame origin. This origin may move up and down in
 * flight due to sensor drift.
 * Set to 1 to control height relative to estimated distance to ground. The vehicle will move up and down
 * with terrain height variation. Requires a distance to ground sensor. The height controller will
 * revert to using height above origin if the distance to ground estimate becomes invalid as indicated
 * by the local_position.distance_bottom_valid message being false.
 * Set to 2 to control height relative to ground (requires a distance sensor) when stationary and relative
 * to earth frame origin when moving horizontally.
 * The speed threshold is controlled by the MPC_HOLD_MAX_XY parameter.
 *
 * @min 0
 * @max 2
 * @value 0 Altitude following
 * @value 1 Terrain following
 * @value 2 Terrain hold
 * @group Multicopter Position Control
 */
PARAM_DEFINE_INT32(MPC_ALT_MODE, 0);

/**
 * Manual position control stick exponential curve sensitivity
 *
 * The higher the value the less sensitivity the stick has around zero
 * while still reaching the maximum value with full stick deflection.
 *
 * 0 Purely linear input curve (default)
 * 1 Purely cubic input curve
 *
 * @min 0
 * @max 1
 * @decimal 2
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_XY_MAN_EXPO, 0.6f);

/**
 * Manual control stick vertical exponential curve
 *
 * The higher the value the less sensitivity the stick has around zero
 * while still reaching the maximum value with full stick deflection.
 *
 * 0 Purely linear input curve (default)
 * 1 Purely cubic input curve
 *
 * @min 0
 * @max 1
 * @decimal 2
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_Z_MAN_EXPO, 0.6f);

/**
 * Manual control stick yaw rotation exponential curve
 *
 * The higher the value the less sensitivity the stick has around zero
 * while still reaching the maximum value with full stick deflection.
 *
 * 0 Purely linear input curve (default)
 * 1 Purely cubic input curve
 *
 * @min 0
 * @max 1
 * @decimal 2
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_YAW_EXPO, 0.6f);

/**
 * Max yaw rate in auto mode
 *
 * Limit the rate of change of the yaw setpoint in autonomous mode
 * to avoid large control output and mixer saturation.
 *
 * @unit deg/s
 * @min 0.0
 * @max 360.0
 * @decimal 1
 * @increment 5
 * @group Multicopter Attitude Control
 */
PARAM_DEFINE_FLOAT(MPC_YAWRAUTO_MAX, 45.0f);

/**
 * Altitude for 1. step of slow landing (descend)
 *
 * Below this altitude:
 * - descending velocity gets limited to a value
 * between "MPC_Z_VEL_MAX" and "MPC_LAND_SPEED"
 * - horizontal velocity gets limited to a value
 * between "MPC_VEL_MANUAL" and "MPC_LAND_VEL_XY"
 * for a smooth descent and landing experience.
 * Value needs to be higher than "MPC_LAND_ALT2"
 *
 * @unit m
 * @min 0
 * @max 122
 * @decimal 1
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_LAND_ALT1, 5.0f);

/**
 * Altitude for 2. step of slow landing (landing)
 *
 * Below this altitude descending and horizontal velocities get
 * limited to "MPC_LAND_SPEED" and "MPC_LAND_VEL_XY", respectively.
 * Value needs to be lower than "MPC_LAND_ALT1"
 *
 * @unit m
 * @min 0
 * @max 122
 * @decimal 1
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_LAND_ALT2, 2.0f);

/**
 * Position control smooth takeoff ramp time constant
 *
 * Increasing this value will make automatic and manual takeoff slower.
 * If it's too slow the drone might scratch the ground and tip over.
 * A time constant of 0 disables the ramp
 *
 * @min 0
 * @max 5
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_TKO_RAMP_T, 3.0f);

/**
 * Manual-Position control sub-mode
 *
 * The supported sub-modes are:
 * 0 Simple position control where sticks map directly to velocity setpoints
 *   without smoothing. Useful for velocity control tuning.
 * 1 Smooth position control with maximum acceleration and jerk limits based on slew-rates.
 * 3 Smooth position control with maximum acceleration and jerk limits based on
 *   jerk optimized trajectory generator (different algorithm than 1).
 *
 * @value 0 Simple position control
 * @value 1 Smooth position control
 * @value 3 Smooth position control (Jerk optimized)
 * @group Multicopter Position Control
 */
PARAM_DEFINE_INT32(MPC_POS_MODE, 3);

/**
 * Enforced delay between arming and takeoff
 *
 * For altitude controlled modes the time from arming the motors until
 * a takeoff is possible gets forced to be at least MPC_SPOOLUP_TIME seconds
 * to ensure the motors and propellers can sppol up and reach idle speed before
 * getting commanded to spin faster. This delay is particularly useful for vehicles
 * with slow motor spin-up e.g. because of large propellers.
 *
 * @min 0
 * @max 10
 * @unit s
 * @group Multicopter Position Control
 */
PARAM_DEFINE_FLOAT(MPC_SPOOLUP_TIME, 1.0f);

/**
 * Yaw mode.
 *
 * Specifies the heading in Auto.
 *
 * @min 0
 * @max 4
 * @value 0 towards waypoint
 * @value 1 towards home
 * @value 2 away from home
 * @value 3 along trajectory
 * @value 4 towards waypoint (yaw first)
 * @group Mission
 */
PARAM_DEFINE_INT32(MPC_YAW_MODE, 0);

/**
 * Acceleration to tilt coupling
 *
 * Set to decouple tilt from vertical acceleration.
 *
 * @boolean
 * @group Multicopter Position Control
 */
PARAM_DEFINE_INT32(MPC_ACC_DECOUPLE, 1);

/**
 * Maximum direct-force (horizontal) scaled thrust for omnidirectional vehicles
 *
 * Specifies the maximum horizontal thrust compared to the maximum possible
 * thrust generated by the vehicle for an omnidirectional multirotor. The
 * value of this parameter does not affect the behavior if the attitude mode
 * is not set to one of omni-directional modes (if OMNI_ATT_MODE is 0).
 *
 * @min 0
 * @max 1
 * @decimal 2
 * @group Multicopter Attitude Control
 */
PARAM_DEFINE_FLOAT(OMNI_DFC_MAX_THR, 0.15f);

/**
 * Omni-directional attitude setpoint mode
 *
 * Specifies the type of attitude setpoint sent to the attitude controller.
 * The parameter can be set to a normal attitude setpoint, where the tilt
 * of the vehicle (roll and pitch) are calculated from the desired thrust
 * vector. This should be the behavior for the non-omnidirectional vehicles,
 * such as quadrotors and other multirotors with coplanar rotors.
 * The "constant zero tilt" mode enforces zero roll and pitch and can only be
 * used for omnidirectional vehicles. The min-tilt mode enforces zero tilt
 * up to a maximum set acceleration (thrust) and tilts the vehicle as small
 * as possible if the thrust vector is larger than the maximum. The "constant
 * tilt" and "constant roll/pitch" modes enforce a given tilt or roll/pitch
 * for the vehicle. The estimation modes estimate the optimal tilt or roll/pitch
 * to counteract with the external force (e.g., wind).
 *
 * @min 0
 * @max 6
 * @value 0 tilted attitude
 * @value 1 min-tilt attitude
 * @value 2 constant zero tilt
 * @value 3 constant tilt
 * @value 4 constant roll/pitch
 * @value 5 estimate tilt/roll/pitch
 * @value 6 slow attitude change
 * @group Multicopter Attitude Control
 */
PARAM_DEFINE_INT32(OMNI_ATT_MODE, 0);

/**
 * Omni-directional attitude setpoint tilt angle
 *
 * Specifies the tilt angle in degrees for the constant-tilt attitude
 * setpoint generation mode (OMNI_ATT_MODE=3).
 *
 * @min 0
 * @max 90
 * @decimal 2
 * @group Multicopter Attitude Control
 */
PARAM_DEFINE_FLOAT(OMNI_ATT_TLT_ANG, 0.0f);

/**
 * Omni-directional attitude setpoint tilt direction angle
 *
 * Specifies the direction of the tilt in degrees for the constant-tilt
 * attitude setpoint generation mode (OMNI_ATT_MODE=3). The direction is
 * measured from North.
 *
 * @min -360
 * @max 360
 * @decimal 2
 * @group Multicopter Attitude Control
 */
PARAM_DEFINE_FLOAT(OMNI_ATT_TLT_DIR, 0.0f);

/**
 * Omni-directional attitude setpoint roll angle
 *
 * Specifies the roll angle in degrees for the constant-roll/pitch attitude
 * setpoint generation mode (OMNI_ATT_MODE=4).
 *
 * @min -90
 * @max 90
 * @decimal 2
 * @group Multicopter Attitude Control
 */
PARAM_DEFINE_FLOAT(OMNI_ATT_ROLL, 0.0f);

/**
 * Omni-directional attitude setpoint pitch angle
 *
 * Specifies the pitch angle in degrees for the constant-roll/pitch attitude
 * setpoint generation mode (OMNI_ATT_MODE=4).
 *
 * @min -90
 * @max 90
 * @decimal 2
 * @group Multicopter Attitude Control
 */
PARAM_DEFINE_FLOAT(OMNI_ATT_PITCH, 0.0f);

/**
 * Axes for thrust projection in omni-directional attitude modes
 *
 * Specifies the axis used for projecting inertial thrust setpoint
 * to the body-fixed frame in omni-directional modes (OMNI_ATT_MODE > 0).
 *
 * @min 0
 * @max 1
 * @value 0 commanded attitude
 * @value 1 current attitude
 * @group Multicopter Attitude Control
 */
PARAM_DEFINE_INT32(OMNI_PROJ_AXES, 1);


/**
 * Rate for change of attitude
 *
 * Specifies the rate in which the attitude can change in slow attitude mode
 * (OMNI_ATT_MODE = 6), rotating the Z axis from the current attitude to the
 * optimal attitude. The value is in degrees per position control loop.
 *
 * @min 0
 * @decimal 3
 * @group Multicopter Attitude Control
 */
PARAM_DEFINE_FLOAT(OMNI_ATT_RATE, 0.5f);
