
#ifndef UTILS_H_
#define UTILS_H_

//OPERATIONS
#define SET_BIT(REG,INDEX)		REG|=(1<<INDEX)
#define CLEAR_BIT(REG,INDEX)	REG&=~(1<<INDEX)
#define GET_BIT(REG,INDEX)		((REG>>INDEX)&0x01) //RETURN 0X00 OR 0X01
#define TOGGLE_BIT(REG,INDEX)   REG^=(1<<INDEX)

#endif /* UTILS_H_ */
