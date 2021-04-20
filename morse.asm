;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.0.0 #11528 (Linux)
;--------------------------------------------------------
	.module morse
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _dah
	.globl _dih
	.globl _intra_duration_words
	.globl _intra_duration_chars
	.globl _intra_duration_char
	.globl _morse_wpm_increase
	.globl _morse_wpm_decrease
	.globl _morse_init
	.globl _delay
	.globl _CY
	.globl _AC
	.globl _F0
	.globl _RS1
	.globl _RS0
	.globl _OV
	.globl _F1
	.globl _P
	.globl _PS
	.globl _PT1
	.globl _PX1
	.globl _PT0
	.globl _PX0
	.globl _RD
	.globl _WR
	.globl _T1
	.globl _T0
	.globl _INT1
	.globl _INT0
	.globl _TXD
	.globl _RXD
	.globl _P3_7
	.globl _P3_6
	.globl _P3_5
	.globl _P3_4
	.globl _P3_3
	.globl _P3_2
	.globl _P3_1
	.globl _P3_0
	.globl _EA
	.globl _ES
	.globl _ET1
	.globl _EX1
	.globl _ET0
	.globl _EX0
	.globl _P2_7
	.globl _P2_6
	.globl _P2_5
	.globl _P2_4
	.globl _P2_3
	.globl _P2_2
	.globl _P2_1
	.globl _P2_0
	.globl _SM0
	.globl _SM1
	.globl _SM2
	.globl _REN
	.globl _TB8
	.globl _RB8
	.globl _TI
	.globl _RI
	.globl _P1_7
	.globl _P1_6
	.globl _P1_5
	.globl _P1_4
	.globl _P1_3
	.globl _P1_2
	.globl _P1_1
	.globl _P1_0
	.globl _TF1
	.globl _TR1
	.globl _TF0
	.globl _TR0
	.globl _IE1
	.globl _IT1
	.globl _IE0
	.globl _IT0
	.globl _P0_7
	.globl _P0_6
	.globl _P0_5
	.globl _P0_4
	.globl _P0_3
	.globl _P0_2
	.globl _P0_1
	.globl _P0_0
	.globl _B
	.globl _ACC
	.globl _PSW
	.globl _IP
	.globl _P3
	.globl _IE
	.globl _P2
	.globl _SBUF
	.globl _SCON
	.globl _P1
	.globl _TH1
	.globl _TH0
	.globl _TL1
	.globl _TL0
	.globl _TMOD
	.globl _TCON
	.globl _PCON
	.globl _DPH
	.globl _DPL
	.globl _SP
	.globl _P0
	.globl _dot_duration_ms
	.globl _dot_duration
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
G$P0$0_0$0 == 0x0080
_P0	=	0x0080
G$SP$0_0$0 == 0x0081
_SP	=	0x0081
G$DPL$0_0$0 == 0x0082
_DPL	=	0x0082
G$DPH$0_0$0 == 0x0083
_DPH	=	0x0083
G$PCON$0_0$0 == 0x0087
_PCON	=	0x0087
G$TCON$0_0$0 == 0x0088
_TCON	=	0x0088
G$TMOD$0_0$0 == 0x0089
_TMOD	=	0x0089
G$TL0$0_0$0 == 0x008a
_TL0	=	0x008a
G$TL1$0_0$0 == 0x008b
_TL1	=	0x008b
G$TH0$0_0$0 == 0x008c
_TH0	=	0x008c
G$TH1$0_0$0 == 0x008d
_TH1	=	0x008d
G$P1$0_0$0 == 0x0090
_P1	=	0x0090
G$SCON$0_0$0 == 0x0098
_SCON	=	0x0098
G$SBUF$0_0$0 == 0x0099
_SBUF	=	0x0099
G$P2$0_0$0 == 0x00a0
_P2	=	0x00a0
G$IE$0_0$0 == 0x00a8
_IE	=	0x00a8
G$P3$0_0$0 == 0x00b0
_P3	=	0x00b0
G$IP$0_0$0 == 0x00b8
_IP	=	0x00b8
G$PSW$0_0$0 == 0x00d0
_PSW	=	0x00d0
G$ACC$0_0$0 == 0x00e0
_ACC	=	0x00e0
G$B$0_0$0 == 0x00f0
_B	=	0x00f0
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
G$P0_0$0_0$0 == 0x0080
_P0_0	=	0x0080
G$P0_1$0_0$0 == 0x0081
_P0_1	=	0x0081
G$P0_2$0_0$0 == 0x0082
_P0_2	=	0x0082
G$P0_3$0_0$0 == 0x0083
_P0_3	=	0x0083
G$P0_4$0_0$0 == 0x0084
_P0_4	=	0x0084
G$P0_5$0_0$0 == 0x0085
_P0_5	=	0x0085
G$P0_6$0_0$0 == 0x0086
_P0_6	=	0x0086
G$P0_7$0_0$0 == 0x0087
_P0_7	=	0x0087
G$IT0$0_0$0 == 0x0088
_IT0	=	0x0088
G$IE0$0_0$0 == 0x0089
_IE0	=	0x0089
G$IT1$0_0$0 == 0x008a
_IT1	=	0x008a
G$IE1$0_0$0 == 0x008b
_IE1	=	0x008b
G$TR0$0_0$0 == 0x008c
_TR0	=	0x008c
G$TF0$0_0$0 == 0x008d
_TF0	=	0x008d
G$TR1$0_0$0 == 0x008e
_TR1	=	0x008e
G$TF1$0_0$0 == 0x008f
_TF1	=	0x008f
G$P1_0$0_0$0 == 0x0090
_P1_0	=	0x0090
G$P1_1$0_0$0 == 0x0091
_P1_1	=	0x0091
G$P1_2$0_0$0 == 0x0092
_P1_2	=	0x0092
G$P1_3$0_0$0 == 0x0093
_P1_3	=	0x0093
G$P1_4$0_0$0 == 0x0094
_P1_4	=	0x0094
G$P1_5$0_0$0 == 0x0095
_P1_5	=	0x0095
G$P1_6$0_0$0 == 0x0096
_P1_6	=	0x0096
G$P1_7$0_0$0 == 0x0097
_P1_7	=	0x0097
G$RI$0_0$0 == 0x0098
_RI	=	0x0098
G$TI$0_0$0 == 0x0099
_TI	=	0x0099
G$RB8$0_0$0 == 0x009a
_RB8	=	0x009a
G$TB8$0_0$0 == 0x009b
_TB8	=	0x009b
G$REN$0_0$0 == 0x009c
_REN	=	0x009c
G$SM2$0_0$0 == 0x009d
_SM2	=	0x009d
G$SM1$0_0$0 == 0x009e
_SM1	=	0x009e
G$SM0$0_0$0 == 0x009f
_SM0	=	0x009f
G$P2_0$0_0$0 == 0x00a0
_P2_0	=	0x00a0
G$P2_1$0_0$0 == 0x00a1
_P2_1	=	0x00a1
G$P2_2$0_0$0 == 0x00a2
_P2_2	=	0x00a2
G$P2_3$0_0$0 == 0x00a3
_P2_3	=	0x00a3
G$P2_4$0_0$0 == 0x00a4
_P2_4	=	0x00a4
G$P2_5$0_0$0 == 0x00a5
_P2_5	=	0x00a5
G$P2_6$0_0$0 == 0x00a6
_P2_6	=	0x00a6
G$P2_7$0_0$0 == 0x00a7
_P2_7	=	0x00a7
G$EX0$0_0$0 == 0x00a8
_EX0	=	0x00a8
G$ET0$0_0$0 == 0x00a9
_ET0	=	0x00a9
G$EX1$0_0$0 == 0x00aa
_EX1	=	0x00aa
G$ET1$0_0$0 == 0x00ab
_ET1	=	0x00ab
G$ES$0_0$0 == 0x00ac
_ES	=	0x00ac
G$EA$0_0$0 == 0x00af
_EA	=	0x00af
G$P3_0$0_0$0 == 0x00b0
_P3_0	=	0x00b0
G$P3_1$0_0$0 == 0x00b1
_P3_1	=	0x00b1
G$P3_2$0_0$0 == 0x00b2
_P3_2	=	0x00b2
G$P3_3$0_0$0 == 0x00b3
_P3_3	=	0x00b3
G$P3_4$0_0$0 == 0x00b4
_P3_4	=	0x00b4
G$P3_5$0_0$0 == 0x00b5
_P3_5	=	0x00b5
G$P3_6$0_0$0 == 0x00b6
_P3_6	=	0x00b6
G$P3_7$0_0$0 == 0x00b7
_P3_7	=	0x00b7
G$RXD$0_0$0 == 0x00b0
_RXD	=	0x00b0
G$TXD$0_0$0 == 0x00b1
_TXD	=	0x00b1
G$INT0$0_0$0 == 0x00b2
_INT0	=	0x00b2
G$INT1$0_0$0 == 0x00b3
_INT1	=	0x00b3
G$T0$0_0$0 == 0x00b4
_T0	=	0x00b4
G$T1$0_0$0 == 0x00b5
_T1	=	0x00b5
G$WR$0_0$0 == 0x00b6
_WR	=	0x00b6
G$RD$0_0$0 == 0x00b7
_RD	=	0x00b7
G$PX0$0_0$0 == 0x00b8
_PX0	=	0x00b8
G$PT0$0_0$0 == 0x00b9
_PT0	=	0x00b9
G$PX1$0_0$0 == 0x00ba
_PX1	=	0x00ba
G$PT1$0_0$0 == 0x00bb
_PT1	=	0x00bb
G$PS$0_0$0 == 0x00bc
_PS	=	0x00bc
G$P$0_0$0 == 0x00d0
_P	=	0x00d0
G$F1$0_0$0 == 0x00d1
_F1	=	0x00d1
G$OV$0_0$0 == 0x00d2
_OV	=	0x00d2
G$RS0$0_0$0 == 0x00d3
_RS0	=	0x00d3
G$RS1$0_0$0 == 0x00d4
_RS1	=	0x00d4
G$F0$0_0$0 == 0x00d5
_F0	=	0x00d5
G$AC$0_0$0 == 0x00d6
_AC	=	0x00d6
G$CY$0_0$0 == 0x00d7
_CY	=	0x00d7
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
G$dot_duration_ms$0_0$0==.
_dot_duration_ms::
	.ds 2
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'morse_init'
;------------------------------------------------------------
	G$morse_init$0$0 ==.
	C$morse.c$25$0_0$4 ==.
;	morse.c:25: void morse_init(void) {
;	-----------------------------------------
;	 function morse_init
;	-----------------------------------------
_morse_init:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	C$morse.c$26$1_0$4 ==.
;	morse.c:26: dot_duration_ms = WPM_BASE_TIME;
	mov	_dot_duration_ms,#0x32
	mov	(_dot_duration_ms + 1),#0x00
	C$morse.c$27$1_0$4 ==.
;	morse.c:27: }
	C$morse.c$27$1_0$4 ==.
	XG$morse_init$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'morse_wpm_decrease'
;------------------------------------------------------------
	G$morse_wpm_decrease$0$0 ==.
	C$morse.c$29$1_0$5 ==.
;	morse.c:29: void morse_wpm_decrease() {
;	-----------------------------------------
;	 function morse_wpm_decrease
;	-----------------------------------------
_morse_wpm_decrease:
	C$morse.c$30$1_0$5 ==.
;	morse.c:30: if (dot_duration_ms > 5) {
	clr	c
	mov	a,#0x05
	subb	a,_dot_duration_ms
	clr	a
	subb	a,(_dot_duration_ms + 1)
	jnc	00103$
	C$morse.c$31$2_0$6 ==.
;	morse.c:31: dot_duration_ms -= 1;  
	dec	_dot_duration_ms
	mov	a,#0xff
	cjne	a,_dot_duration_ms,00110$
	dec	(_dot_duration_ms + 1)
00110$:
00103$:
	C$morse.c$33$1_0$5 ==.
;	morse.c:33: }
	C$morse.c$33$1_0$5 ==.
	XG$morse_wpm_decrease$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'morse_wpm_increase'
;------------------------------------------------------------
	G$morse_wpm_increase$0$0 ==.
	C$morse.c$35$1_0$7 ==.
;	morse.c:35: void morse_wpm_increase() {
;	-----------------------------------------
;	 function morse_wpm_increase
;	-----------------------------------------
_morse_wpm_increase:
	C$morse.c$36$1_0$7 ==.
;	morse.c:36: if (dot_duration_ms < 250) {
	clr	c
	mov	a,_dot_duration_ms
	subb	a,#0xfa
	mov	a,(_dot_duration_ms + 1)
	subb	a,#0x00
	jnc	00103$
	C$morse.c$37$2_0$8 ==.
;	morse.c:37: dot_duration_ms += 1;  
	mov	a,#0x01
	add	a,_dot_duration_ms
	mov	_dot_duration_ms,a
	clr	a
	addc	a,(_dot_duration_ms + 1)
	mov	(_dot_duration_ms + 1),a
00103$:
	C$morse.c$39$1_0$7 ==.
;	morse.c:39: }
	C$morse.c$39$1_0$7 ==.
	XG$morse_wpm_increase$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'dot_duration'
;------------------------------------------------------------
;n_times                   Allocated to registers r6 r7 
;n                         Allocated to registers r4 r5 
;------------------------------------------------------------
	G$dot_duration$0$0 ==.
	C$morse.c$41$1_0$10 ==.
;	morse.c:41: void dot_duration(unsigned int n_times) {
;	-----------------------------------------
;	 function dot_duration
;	-----------------------------------------
_dot_duration:
	mov	r6,dpl
	mov	r7,dph
	C$morse.c$44$1_0$10 ==.
;	morse.c:44: if (!n_times) {
	mov	a,r6
	orl	a,r7
	C$morse.c$45$2_0$11 ==.
;	morse.c:45: n = 1;
	jnz	00102$
	mov	r4,#0x01
	mov	r5,a
	sjmp	00103$
00102$:
	C$morse.c$47$2_0$12 ==.
;	morse.c:47: n = n_times;
	mov	ar4,r6
	mov	ar5,r7
00103$:
	C$morse.c$50$1_0$10 ==.
;	morse.c:50: delay((dot_duration_ms * n));
	mov	__mulint_PARM_2,r4
	mov	(__mulint_PARM_2 + 1),r5
	mov	dpl,_dot_duration_ms
	mov	dph,(_dot_duration_ms + 1)
	lcall	__mulint
	lcall	_delay
	C$morse.c$51$1_0$10 ==.
;	morse.c:51: }
	C$morse.c$51$1_0$10 ==.
	XG$dot_duration$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'intra_duration_char'
;------------------------------------------------------------
	G$intra_duration_char$0$0 ==.
	C$morse.c$53$1_0$14 ==.
;	morse.c:53: void intra_duration_char(void) {
;	-----------------------------------------
;	 function intra_duration_char
;	-----------------------------------------
_intra_duration_char:
	C$morse.c$54$1_0$14 ==.
;	morse.c:54: dot_duration(1);   
	mov	dptr,#0x0001
	lcall	_dot_duration
	C$morse.c$55$1_0$14 ==.
;	morse.c:55: }
	C$morse.c$55$1_0$14 ==.
	XG$intra_duration_char$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'intra_duration_chars'
;------------------------------------------------------------
	G$intra_duration_chars$0$0 ==.
	C$morse.c$57$1_0$16 ==.
;	morse.c:57: void intra_duration_chars(void) {
;	-----------------------------------------
;	 function intra_duration_chars
;	-----------------------------------------
_intra_duration_chars:
	C$morse.c$58$1_0$16 ==.
;	morse.c:58: dot_duration(3);  
	mov	dptr,#0x0003
	lcall	_dot_duration
	C$morse.c$59$1_0$16 ==.
;	morse.c:59: }
	C$morse.c$59$1_0$16 ==.
	XG$intra_duration_chars$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'intra_duration_words'
;------------------------------------------------------------
	G$intra_duration_words$0$0 ==.
	C$morse.c$61$1_0$18 ==.
;	morse.c:61: void intra_duration_words(void) {
;	-----------------------------------------
;	 function intra_duration_words
;	-----------------------------------------
_intra_duration_words:
	C$morse.c$62$1_0$18 ==.
;	morse.c:62: dot_duration(7);   
	mov	dptr,#0x0007
	lcall	_dot_duration
	C$morse.c$63$1_0$18 ==.
;	morse.c:63: }
	C$morse.c$63$1_0$18 ==.
	XG$intra_duration_words$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'dih'
;------------------------------------------------------------
	G$dih$0$0 ==.
	C$morse.c$65$1_0$20 ==.
;	morse.c:65: void dih(void) {
;	-----------------------------------------
;	 function dih
;	-----------------------------------------
_dih:
	C$morse.c$66$1_0$20 ==.
;	morse.c:66: OUT_MORSE = 1;
;	assignBit
	setb	_P1_1
	C$morse.c$67$1_0$20 ==.
;	morse.c:67: dot_duration(1);
	mov	dptr,#0x0001
	lcall	_dot_duration
	C$morse.c$68$1_0$20 ==.
;	morse.c:68: OUT_MORSE = 0;
;	assignBit
	clr	_P1_1
	C$morse.c$69$1_0$20 ==.
;	morse.c:69: }
	C$morse.c$69$1_0$20 ==.
	XG$dih$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'dah'
;------------------------------------------------------------
	G$dah$0$0 ==.
	C$morse.c$71$1_0$22 ==.
;	morse.c:71: void dah(void) {
;	-----------------------------------------
;	 function dah
;	-----------------------------------------
_dah:
	C$morse.c$72$1_0$22 ==.
;	morse.c:72: OUT_MORSE = 1;
;	assignBit
	setb	_P1_1
	C$morse.c$73$1_0$22 ==.
;	morse.c:73: dot_duration(3);
	mov	dptr,#0x0003
	lcall	_dot_duration
	C$morse.c$74$1_0$22 ==.
;	morse.c:74: OUT_MORSE = 0;
;	assignBit
	clr	_P1_1
	C$morse.c$75$1_0$22 ==.
;	morse.c:75: }
	C$morse.c$75$1_0$22 ==.
	XG$dah$0$0 ==.
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
