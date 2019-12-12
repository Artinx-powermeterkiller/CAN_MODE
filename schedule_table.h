#ifndef  SCHEDULE_TABLE_H
#define SCHEDULE_TABLE_H

#define PUBLIC_BASE_ID 0x000

enum PUBLIC_FUNCTION
{
	CONTROL=0x001,
	CLOCK=0x002,
	READY=0x003
};


#define GIMALE_BASE_ID 0x010

enum GIMBAL_FUNCTION
{
	JUDGEMENT_17MM = 0x031,
	JUDGEMENT_BUFF =0x032,
};

#define CHASSIS_BASE_ID 0x030

enum CHASSIS_FUNCTION
{

};

#define SUPERC_BASE_ID

enum SUPERC_FUNCTION
{
	SUPERC_ON_TIME_POWER = 0x000,
	SUPERC_CAP_STATE = 0x001
};


enum IMU_BASE_ID
{
	IMU_1_ID = 0x131,
	IMU_2_ID = 0x132,
	IMU_3_ID = 0x133,
	IMU_4_ID = 0x134
};

enum IMU_FUNCTION
{
	IMU_ANGLE=0x000,
	IMU_ACC=0x010,
	IMU_ANGLE_SPEED=0x020
};

typedef struct
{
	int* schedule_table;
	int table_length;
} channl_schedule_table_t;

#endif // ! SCHEDULE_TABLE_H

