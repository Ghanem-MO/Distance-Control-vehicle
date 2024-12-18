/*
 * Timer1.c
 *
 *  Created on: Oct 22, 2023
 *      Author: TOP_WORLD
 */
#include "Timer1.h"
void (*Gptr_3)(void)='\0';
u8 MCAL_T1_u8T1Init(u8 LOC_u8Timer1Mode) {
	u8 LOC_u8ReturnValue = E_NOT_OK;
	if (LOC_u8Timer1Mode <= FAST_PWM_OCR1A) {
		if (LOC_u8Timer1Mode == NORMAL_MODE) {
			CLR_BIT(TCCR1A, PIN0);
			CLR_BIT(TCCR1A, PIN1);
			CLR_BIT(TCCR1B, PIN3);
			CLR_BIT(TCCR1B, PIN4);
			LOC_u8ReturnValue = E_OK;
		} else if (LOC_u8Timer1Mode == PWM_PHASE_CORRECT_8bit) {
			SET_BIT(TCCR1A, PIN0);
			CLR_BIT(TCCR1A, PIN1);
			CLR_BIT(TCCR1B, PIN3);
			CLR_BIT(TCCR1B, PIN4);
			LOC_u8ReturnValue = E_OK;
		} else if (LOC_u8Timer1Mode == PWM_PHASE_CORRECT_9bit) {
			CLR_BIT(TCCR1A, PIN0);
			SET_BIT(TCCR1A, PIN1);
			CLR_BIT(TCCR1B, PIN3);
			CLR_BIT(TCCR1B, PIN4);
			LOC_u8ReturnValue = E_OK;
		} else if (LOC_u8Timer1Mode == PWM_PHASE_CORRECT_10bit) {
			SET_BIT(TCCR1A, PIN0);
			SET_BIT(TCCR1A, PIN1);
			CLR_BIT(TCCR1B, PIN3);
			CLR_BIT(TCCR1B, PIN4);
			LOC_u8ReturnValue = E_OK;
		} else if (LOC_u8Timer1Mode == CTC_OCR1A) {
			CLR_BIT(TCCR1A, PIN0);
			CLR_BIT(TCCR1A, PIN1);
			SET_BIT(TCCR1B, PIN3);
			CLR_BIT(TCCR1B, PIN4);
			LOC_u8ReturnValue = E_OK;
		} else if (LOC_u8Timer1Mode == FAST_PWM_8bit) {
			SET_BIT(TCCR1A, PIN0);
			CLR_BIT(TCCR1A, PIN1);
			SET_BIT(TCCR1B, PIN3);
			CLR_BIT(TCCR1B, PIN4);
			LOC_u8ReturnValue = E_OK;
		} else if (LOC_u8Timer1Mode == FAST_PWM_9bit) {
			CLR_BIT(TCCR1A, PIN0);
			SET_BIT(TCCR1A, PIN1);
			SET_BIT(TCCR1B, PIN3);
			CLR_BIT(TCCR1B, PIN4);
			LOC_u8ReturnValue = E_OK;
		} else if (LOC_u8Timer1Mode == FAST_PWM_10bit) {
			SET_BIT(TCCR1A, PIN0);
			SET_BIT(TCCR1A, PIN1);
			SET_BIT(TCCR1B, PIN3);
			CLR_BIT(TCCR1B, PIN4);
			LOC_u8ReturnValue = E_OK;
		} else if (LOC_u8Timer1Mode == PWM_PHASE_AND_FREQUANCY_CORRECT_ICR1) {
			CLR_BIT(TCCR1A, PIN0);
			CLR_BIT(TCCR1A, PIN1);
			CLR_BIT(TCCR1B, PIN3);
			SET_BIT(TCCR1B, PIN4);
			LOC_u8ReturnValue = E_OK;
		} else if (LOC_u8Timer1Mode == PWM_PHASE_AND_FREQUANCY_CORRECT_OCR1A) {
			SET_BIT(TCCR1A, PIN0);
			CLR_BIT(TCCR1A, PIN1);
			CLR_BIT(TCCR1B, PIN3);
			SET_BIT(TCCR1B, PIN4);
			LOC_u8ReturnValue = E_OK;
		} else if (LOC_u8Timer1Mode == PWM_PHASE_CORRECT_ICR1) {
			CLR_BIT(TCCR1A, PIN0);
			SET_BIT(TCCR1A, PIN1);
			CLR_BIT(TCCR1B, PIN3);
			SET_BIT(TCCR1B, PIN4);
			LOC_u8ReturnValue = E_OK;
		} else if (LOC_u8Timer1Mode == PWM_PHASE_CORRECT_OCR1A) {
			SET_BIT(TCCR1A, PIN0);
			SET_BIT(TCCR1A, PIN1);
			CLR_BIT(TCCR1B, PIN3);
			SET_BIT(TCCR1B, PIN4);
			LOC_u8ReturnValue = E_OK;
		} else if (LOC_u8Timer1Mode == CTC_ICR1) {
			CLR_BIT(TCCR1A, PIN0);
			CLR_BIT(TCCR1A, PIN1);
			SET_BIT(TCCR1B, PIN3);
			SET_BIT(TCCR1B, PIN4);
			LOC_u8ReturnValue = E_OK;
		} else if (LOC_u8Timer1Mode == REVERSED_MODE) {
			SET_BIT(TCCR1A, PIN0);
			CLR_BIT(TCCR1A, PIN1);
			SET_BIT(TCCR1B, PIN3);
			SET_BIT(TCCR1B, PIN4);
			LOC_u8ReturnValue = E_OK;
		} else if (LOC_u8Timer1Mode == FAST_PWM_ICR1) {
			CLR_BIT(TCCR1A, PIN0);
			SET_BIT(TCCR1A, PIN1);
			SET_BIT(TCCR1B, PIN3);
			SET_BIT(TCCR1B, PIN4);
			LOC_u8ReturnValue = E_OK;
		} else if (LOC_u8Timer1Mode == FAST_PWM_OCR1A) {
			SET_BIT(TCCR1A, PIN0);
			SET_BIT(TCCR1A, PIN1);
			SET_BIT(TCCR1B, PIN3);
			SET_BIT(TCCR1B, PIN4);
			LOC_u8ReturnValue = E_OK;
		} else {
			//NOTHING
		}
	} else {
		//NOTHING
	}
	return LOC_u8ReturnValue;
}
u8 MCAL_T1_u8T1Prescaler(u8 LOC_u8Clock_Selection, f32 *LOC_pfl32TickTime) {
	u8 LOC_u8ReturnValue = E_NOT_OK;
	if (LOC_u8Clock_Selection <= EXTERNAL_RISING_EDGE) {
		if (LOC_u8Clock_Selection == COUNTER_STOP) {
			CLR_BIT(TCCR1B, PIN0);
			CLR_BIT(TCCR1B, PIN1);
			CLR_BIT(TCCR1B, PIN2);
			LOC_u8ReturnValue = E_OK;
		} else if (LOC_u8Clock_Selection == PRESCALLING_0) {
			SET_BIT(TCCR1B, PIN0);
			CLR_BIT(TCCR1B, PIN1);
			CLR_BIT(TCCR1B, PIN2);
			*LOC_pfl32TickTime = PRESCALLING0 / (f32) CPU_FREQUNCY;
			LOC_u8ReturnValue = E_OK;
		} else if (LOC_u8Clock_Selection == PRESCALLING_8) {
			CLR_BIT(TCCR1B, PIN0);
			SET_BIT(TCCR1B, PIN1);
			CLR_BIT(TCCR1B, PIN2);
			*LOC_pfl32TickTime = PRESCALLING8 / (f32) CPU_FREQUNCY;
			LOC_u8ReturnValue = E_OK;
		} else if (LOC_u8Clock_Selection == PRESCALLING_64) {
			SET_BIT(TCCR1B, PIN0);
			SET_BIT(TCCR1B, PIN1);
			CLR_BIT(TCCR1B, PIN2);
			*LOC_pfl32TickTime = PRESCALLING64 / (f32) CPU_FREQUNCY;
			LOC_u8ReturnValue = E_OK;
		} else if (LOC_u8Clock_Selection == PRESCALLING_256) {
			CLR_BIT(TCCR1B, PIN0);
			CLR_BIT(TCCR1B, PIN1);
			SET_BIT(TCCR1B, PIN2);
			*LOC_pfl32TickTime = PRESCALLING256 / (f32) CPU_FREQUNCY;
			LOC_u8ReturnValue = E_OK;
		} else if (LOC_u8Clock_Selection == PRESCALLING_1024) {
			SET_BIT(TCCR1B, PIN0);
			CLR_BIT(TCCR1B, PIN1);
			SET_BIT(TCCR1B, PIN2);
			*LOC_pfl32TickTime = PRESCALLING1024 / (f32) CPU_FREQUNCY;
			LOC_u8ReturnValue = E_OK;
		} else if (LOC_u8Clock_Selection == EXTERNAL_FALLING_EDGE) {
			CLR_BIT(TCCR1B, PIN0);
			SET_BIT(TCCR1B, PIN1);
			SET_BIT(TCCR1B, PIN2);
			LOC_u8ReturnValue = E_OK;
		} else if (LOC_u8Clock_Selection == EXTERNAL_RISING_EDGE) {
			SET_BIT(TCCR1B, PIN0);
			SET_BIT(TCCR1B, PIN1);
			SET_BIT(TCCR1B, PIN2);
			LOC_u8ReturnValue = E_OK;
		} else {
			//NOTHING
		}
	} else {
		//NOTHING
	}
	return LOC_u8ReturnValue;
}
//Fast MODE PWM & PHASE CORRECT
u8 MCAL_T1_u8T1CompareOutputMode(u8 LOC_u8OutputMode, u8 LOC_u8Channel) {
	u8 LOC_u8ReturnValue = E_NOT_OK;
	if (LOC_u8OutputMode <= INVERTING_MODE && LOC_u8Channel <= CHENNEL_B) {
		if (LOC_u8Channel == CHENNEL_A) {
			if (LOC_u8OutputMode == NON_INVERTING_MODE) {
				CLR_BIT(TCCR1A, PIN6);
				SET_BIT(TCCR1A, PIN7);
				SET_BIT(DDRD, PIN5);
				LOC_u8ReturnValue = E_OK;
			} else if (LOC_u8OutputMode == INVERTING_MODE) {
				SET_BIT(TCCR1A, PIN6);
				SET_BIT(TCCR1A, PIN7);
				SET_BIT(DDRD, PIN5);
				LOC_u8ReturnValue = E_OK;
			} else {
				//NOTHING
			}
		} else if (LOC_u8Channel == CHENNEL_B) {
			if (LOC_u8OutputMode == NON_INVERTING_MODE) {
				CLR_BIT(TCCR1A, PIN4);
				SET_BIT(TCCR1A, PIN5);
				SET_BIT(DDRD, PIN4);
				LOC_u8ReturnValue = E_OK;
			} else if (LOC_u8OutputMode == INVERTING_MODE) {
				SET_BIT(TCCR1A, PIN4);
				SET_BIT(TCCR1A, PIN5);
				SET_BIT(DDRD, PIN4);
				LOC_u8ReturnValue = E_OK;
			} else {
				//NOTHING
			}

		} else {
			//NOTHING
		}
	} else {
		//NOTHING
	}
	return LOC_u8ReturnValue;
}
//NOISE CANCLLER
void MCAL_T1_voidNoiseCancller(void) {
	SET_BIT(TCCR1B, PIN7);
}
//Set TCNT1 Value
void MCAL_T1_voidSetTCNT1Value(u16 LOC_u16Value) {
	if (LOC_u16Value <= SIXTEEN_BIT_MAX_VALUE) {
		TCNT1 = LOC_u16Value;
	} else {
		//NOTHING
	}
}
//GIT TCNT1
void MCAL_T1_voidGetTCNT1Value(u16 *LOC_pu16Value) {
	if (LOC_pu16Value) {
		*LOC_pu16Value = TCNT1;
	}
}
//Set OCR1A
void MCAL_T1_voidSetOCR1AValue(u16 LOC_u16Value) {
	if (LOC_u16Value <= SIXTEEN_BIT_MAX_VALUE) {
		OCR1A = LOC_u16Value;
	} else {
		//NOTHING
	}
}
//SET OCR1B
void MCAL_T1_voidSetOCR1BValue(u16 LOC_u16Value) {
	if (LOC_u16Value <= SIXTEEN_BIT_MAX_VALUE) {
		OCR1B = LOC_u16Value;
	} else {
		//NOTHING
	}
}
//SET ICR1
void MCAL_T1_voidSetICR1Value(u16 LOC_u16Value) {
	if (LOC_u16Value <= SIXTEEN_BIT_MAX_VALUE) {
		ICR1 = LOC_u16Value;
	} else {
		//NOTHING
	}
}
//Get ICR1
void MCAL_T1_voidGetICR1Value(u16 *LOC_pu16Value) {
	if (LOC_pu16Value) {
		*LOC_pu16Value =ICR1;
	}
}
//TCNT1 PIE
void MCAL_T1_voidTCNT1_GIEEnable(void) {
	SET_BIT(SREG, PIN7);
	SET_BIT(TIMSK, PIN2);
}
void MCAL_T1_voidTCNT1_GIEDisable(void) {
	CLR_BIT(TIMSK, PIN2);
}
//OCR1B PIE
void MCAL_T1_voidOCR1B_GIEEnable(void) {
	SET_BIT(SREG, PIN7);
	SET_BIT(TIMSK, PIN3);
}
void MCAL_T1_voidOCR1B_GIEDisable(void) {
	CLR_BIT(TIMSK, PIN3);
}
//OCR1A PIE
void MCAL_T1_voidOCR1A_GIEEnable(void) {
	SET_BIT(SREG, PIN7);
	SET_BIT(TIMSK, PIN4);
}
void MCAL_T1_voidOCR1A_GIEDisable(void) {
	CLR_BIT(TIMSK, PIN4);
}
//ICR1 PIE
void MCAL_T1_voidICR1_GIEEnable(void) {
	SET_BIT(SREG, PIN7);
	SET_BIT(TIMSK, PIN5);
}
void MCAL_T1_voidICR1_GIEDisable(void) {
	CLR_BIT(TIMSK, PIN5);
}

u8 MCAL_T1_u8T1DelayNormalMode(u8 LOC_u8Clock_Selection,
		f32 LOC_f32NumOFSecond, u16 *LOC_pu8StartValue, u16 *LOC_pu16Counter) {
	u8 LOC_u8ReturnValue = E_NOT_OK;
	f32 TickTime = NUMBER_0;
	u32 N = NUMBER_0;
	u16 counter = NUMBER_0;
	u16 Reminder = NUMBER_0;
	MCAL_T1_u8T1Prescaler(LOC_u8Clock_Selection, &TickTime);
	if (LOC_f32NumOFSecond <= 0 || LOC_f32NumOFSecond > 0) {
		N = LOC_f32NumOFSecond / (f32) TickTime;
		Reminder = N % OVER_FLOW_COUNT;
		*LOC_pu8StartValue = Reminder;
		if (Reminder == NUMBER_0) {
			MCAL_T1_voidSetTCNT1Value(Reminder);
			counter = N / OVER_FLOW_COUNT;
			*LOC_pu16Counter = counter;
		} else if (Reminder != NUMBER_0) {
			MCAL_T1_voidSetTCNT1Value(Reminder);
			counter = ((N / OVER_FLOW_COUNT) + NUMBER_1);
			*LOC_pu16Counter = counter;
		} else {
			//NOTHING
		}
		LOC_u8ReturnValue = E_OK;
	}
	return LOC_u8ReturnValue;

}

void MCAL_T1_voidDelayCTCMode(u8 LOC_u8Clock_Selection,
		f32 LOC_fl32NumOFSecond, u16 *LOC_pu16Counter) {
	f32 TickTime = NUMBER_0;
	f32 N = NUMBER_0;
	u16 counter = NUMBER_0;
	MCAL_T1_u8T1Prescaler(LOC_u8Clock_Selection, &TickTime);
	MCAL_T1_voidSetOCR1AValue(CTC_DELAY_CONST);
	if (LOC_fl32NumOFSecond <= 0 || LOC_fl32NumOFSecond > 0) {
		N = ((CTC_DELAY_CONST + NUMBER_1) * TickTime);
		counter = (LOC_fl32NumOFSecond / N);
		*LOC_pu16Counter = counter;
	} else {
		//NOTING
	}
}
//ICU EDGE
void MCAL_T1_voidSetTriggerEdge(u8 LOC_u8TriggerEdge) {
	if (LOC_u8TriggerEdge <= RISING_EDGE) {
		if (LOC_u8TriggerEdge == RISING_EDGE) {
			SET_BIT(TCCR1B, PIN6);
		} else if (LOC_u8TriggerEdge == FALLING_EDGE) {
			CLR_BIT(TCCR1B, PIN6);
		} else {
			//NOTHING
		}
	} else {
		//NOTHING
	}
}
u8 MCAL_T1_u8T1_Callback(void (*ptr)(void)) {
	u8 LOC_u8ReturnValue = E_NOT_OK;
	if (ptr != '\0') {
		Gptr_3 = ptr;
		LOC_u8ReturnValue = E_OK;
	}
	return LOC_u8ReturnValue;
}

ISR(TIMER1_OVF_vect) {
	if (Gptr_3 != '\0') {
		Gptr_3();
	}
}
ISR(TIMER1_COMPA_vect) {
	if (Gptr_3 != '\0') {
		Gptr_3();
	}
}
ISR(TIMER1_COMPB_vect) {
	if (Gptr_3 != '\0') {
		Gptr_3();
	}
}
ISR(TIMER1_CAPT_vect) {
	if (Gptr_3 != '\0') {
		Gptr_3();
	}
}

void MCAL_T1_FPWM_10bitRES(u8 copy_u8Channel, u8 copy_u8Duty) {
	f32 LOC_fl32tickTime = 0;
	//Set Mode
	MCAL_T1_u8T1Init(PWM_PHASE_CORRECT_10bit);
	//Select Prescaler
	MCAL_T1_u8T1Prescaler(PRESCALLING_64, &LOC_fl32tickTime);
	MCAL_T1_u8T1CompareOutputMode(NON_INVERTING_MODE, copy_u8Channel);
	if (copy_u8Channel == CHENNEL_A) {
		OCR1A = copy_u8Duty * 10.23;
	} else if (copy_u8Channel == CHENNEL_B) {
		OCR1B = copy_u8Duty * 10.23;

	} else {
		//NOTHING
	}
}
