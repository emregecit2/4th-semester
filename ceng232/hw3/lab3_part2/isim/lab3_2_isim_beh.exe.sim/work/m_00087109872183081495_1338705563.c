/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x9ca8bed6 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "/home/bs2020/e2521581/Desktop/emregecit2@github/4th-semester/ceng232/hw3/lab3_part2/lab3_2.v";
static int ng1[] = {0, 0};
static unsigned int ng2[] = {1U, 0U};
static int ng3[] = {15, 0};
static int ng4[] = {1, 0};
static unsigned int ng5[] = {0U, 0U};



static void Initial_21_0(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(21, ng0);

LAB2:    xsi_set_current_line(22, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 1928);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 6);
    xsi_set_current_line(23, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 2088);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 6);
    xsi_set_current_line(24, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 2248);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(25, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 2408);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(26, ng0);
    t1 = ((char*)((ng2)));
    t2 = (t0 + 2568);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(27, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 2728);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(28, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 2888);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(29, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 3048);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(30, ng0);
    t1 = ((char*)((ng2)));
    t2 = (t0 + 3208);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(31, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 3368);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);

LAB1:    return;
}

static void Always_34_1(char *t0)
{
    char t8[8];
    char t29[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    int t7;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    char *t39;
    char *t40;
    char *t41;

LAB0:    t1 = (t0 + 4528U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(34, ng0);
    t2 = (t0 + 4848);
    *((int *)t2) = 1;
    t3 = (t0 + 4560);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(35, ng0);

LAB5:    xsi_set_current_line(36, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t0 + 3368);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(37, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2728);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(38, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(39, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(40, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);

LAB6:    t2 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_compare(t3, 1, t2, 32);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng4)));
    t6 = xsi_vlog_unsigned_case_compare(t3, 1, t2, 32);
    if (t6 == 1)
        goto LAB9;

LAB10:
LAB11:    goto LAB2;

LAB7:    xsi_set_current_line(41, ng0);

LAB12:    xsi_set_current_line(42, ng0);
    t4 = (t0 + 1528U);
    t5 = *((char **)t4);

LAB13:    t4 = ((char*)((ng2)));
    t7 = xsi_vlog_unsigned_case_compare(t5, 2, t4, 2);
    if (t7 == 1)
        goto LAB14;

LAB15:    t2 = ((char*)((ng5)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 2, t2, 2);
    if (t6 == 1)
        goto LAB16;

LAB17:
LAB18:    goto LAB11;

LAB9:    xsi_set_current_line(67, ng0);

LAB50:    xsi_set_current_line(68, ng0);
    t4 = (t0 + 1528U);
    t9 = *((char **)t4);

LAB51:    t4 = ((char*)((ng2)));
    t7 = xsi_vlog_unsigned_case_compare(t9, 2, t4, 2);
    if (t7 == 1)
        goto LAB52;

LAB53:    t2 = ((char*)((ng5)));
    t6 = xsi_vlog_unsigned_case_compare(t9, 2, t2, 2);
    if (t6 == 1)
        goto LAB54;

LAB55:
LAB56:    goto LAB11;

LAB14:    xsi_set_current_line(43, ng0);

LAB19:    xsi_set_current_line(44, ng0);
    t9 = (t0 + 3048);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memset(t8, 0, 8);
    t12 = (t11 + 4);
    t13 = *((unsigned int *)t12);
    t14 = (~(t13));
    t15 = *((unsigned int *)t11);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB23;

LAB21:    if (*((unsigned int *)t12) == 0)
        goto LAB20;

LAB22:    t18 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t18) = 1;

LAB23:    t19 = (t8 + 4);
    t20 = *((unsigned int *)t19);
    t21 = (~(t20));
    t22 = *((unsigned int *)t8);
    t23 = (t22 & t21);
    t24 = (t23 != 0);
    if (t24 > 0)
        goto LAB24;

LAB25:
LAB26:    goto LAB18;

LAB16:    xsi_set_current_line(59, ng0);

LAB49:    xsi_set_current_line(60, ng0);
    t4 = ((char*)((ng4)));
    t9 = (t0 + 3368);
    xsi_vlogvar_assign_value(t9, t4, 0, 0, 1);
    xsi_set_current_line(61, ng0);
    t2 = (t0 + 2088);
    t4 = (t2 + 56U);
    t9 = *((char **)t4);
    t10 = ((char*)((ng4)));
    memset(t8, 0, 8);
    xsi_vlog_unsigned_minus(t8, 32, t9, 6, t10, 32);
    t11 = (t0 + 2088);
    xsi_vlogvar_assign_value(t11, t8, 0, 0, 6);
    goto LAB18;

LAB20:    *((unsigned int *)t8) = 1;
    goto LAB23;

LAB24:    xsi_set_current_line(44, ng0);

LAB27:    xsi_set_current_line(45, ng0);
    t25 = (t0 + 2088);
    t26 = (t25 + 56U);
    t27 = *((char **)t26);
    t28 = ((char*)((ng3)));
    memset(t29, 0, 8);
    t30 = (t27 + 4);
    if (*((unsigned int *)t30) != 0)
        goto LAB29;

LAB28:    t31 = (t28 + 4);
    if (*((unsigned int *)t31) != 0)
        goto LAB29;

LAB32:    if (*((unsigned int *)t27) < *((unsigned int *)t28))
        goto LAB30;

LAB31:    t33 = (t29 + 4);
    t34 = *((unsigned int *)t33);
    t35 = (~(t34));
    t36 = *((unsigned int *)t29);
    t37 = (t36 & t35);
    t38 = (t37 != 0);
    if (t38 > 0)
        goto LAB33;

LAB34:    xsi_set_current_line(49, ng0);

LAB37:    xsi_set_current_line(50, ng0);
    t2 = (t0 + 1048U);
    t4 = *((char **)t2);
    memset(t8, 0, 8);
    t2 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t14 = *((unsigned int *)t4);
    t14 = (t14 & 1);
    if (*((unsigned int *)t2) != 0)
        goto LAB38;

LAB39:    t15 = 1;

LAB41:    t16 = (t15 <= 4);
    if (t16 == 1)
        goto LAB42;

LAB43:    *((unsigned int *)t8) = t14;

LAB40:    t10 = (t8 + 4);
    t20 = *((unsigned int *)t10);
    t21 = (~(t20));
    t22 = *((unsigned int *)t8);
    t23 = (t22 & t21);
    t24 = (t23 != 0);
    if (t24 > 0)
        goto LAB45;

LAB46:    xsi_set_current_line(54, ng0);
    t2 = ((char*)((ng4)));
    t4 = (t0 + 2888);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);

LAB47:
LAB35:    goto LAB26;

LAB29:    t32 = (t29 + 4);
    *((unsigned int *)t29) = 1;
    *((unsigned int *)t32) = 1;
    goto LAB31;

LAB30:    *((unsigned int *)t29) = 1;
    goto LAB31;

LAB33:    xsi_set_current_line(45, ng0);

LAB36:    xsi_set_current_line(46, ng0);
    t39 = ((char*)((ng4)));
    t40 = (t0 + 3368);
    xsi_vlogvar_assign_value(t40, t39, 0, 0, 1);
    xsi_set_current_line(47, ng0);
    t2 = (t0 + 2088);
    t4 = (t2 + 56U);
    t9 = *((char **)t4);
    t10 = ((char*)((ng4)));
    memset(t8, 0, 8);
    xsi_vlog_unsigned_add(t8, 32, t9, 6, t10, 32);
    t11 = (t0 + 2088);
    xsi_vlogvar_assign_value(t11, t8, 0, 0, 6);
    goto LAB35;

LAB38:    t9 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB40;

LAB42:    t13 = (t13 >> 1);
    t17 = (t13 & 1);
    t14 = (t14 ^ t17);

LAB44:    t15 = (t15 + 1);
    goto LAB41;

LAB45:    xsi_set_current_line(50, ng0);

LAB48:    xsi_set_current_line(51, ng0);
    t11 = ((char*)((ng4)));
    t12 = (t0 + 3368);
    xsi_vlogvar_assign_value(t12, t11, 0, 0, 1);
    xsi_set_current_line(52, ng0);
    t2 = (t0 + 2088);
    t4 = (t2 + 56U);
    t9 = *((char **)t4);
    t10 = ((char*)((ng4)));
    memset(t8, 0, 8);
    xsi_vlog_unsigned_add(t8, 32, t9, 6, t10, 32);
    t11 = (t0 + 2088);
    xsi_vlogvar_assign_value(t11, t8, 0, 0, 6);
    goto LAB47;

LAB52:    xsi_set_current_line(69, ng0);

LAB57:    xsi_set_current_line(70, ng0);
    t10 = (t0 + 2408);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memset(t8, 0, 8);
    t18 = (t12 + 4);
    t13 = *((unsigned int *)t18);
    t14 = (~(t13));
    t15 = *((unsigned int *)t12);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB61;

LAB59:    if (*((unsigned int *)t18) == 0)
        goto LAB58;

LAB60:    t19 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t19) = 1;

LAB61:    t25 = (t8 + 4);
    t20 = *((unsigned int *)t25);
    t21 = (~(t20));
    t22 = *((unsigned int *)t8);
    t23 = (t22 & t21);
    t24 = (t23 != 0);
    if (t24 > 0)
        goto LAB62;

LAB63:
LAB64:    goto LAB56;

LAB54:    xsi_set_current_line(85, ng0);

LAB87:    xsi_set_current_line(86, ng0);
    t4 = ((char*)((ng4)));
    t10 = (t0 + 2728);
    xsi_vlogvar_assign_value(t10, t4, 0, 0, 1);
    xsi_set_current_line(87, ng0);
    t2 = (t0 + 1928);
    t4 = (t2 + 56U);
    t10 = *((char **)t4);
    t11 = ((char*)((ng4)));
    memset(t8, 0, 8);
    xsi_vlog_unsigned_minus(t8, 32, t10, 6, t11, 32);
    t12 = (t0 + 1928);
    xsi_vlogvar_assign_value(t12, t8, 0, 0, 6);
    goto LAB56;

LAB58:    *((unsigned int *)t8) = 1;
    goto LAB61;

LAB62:    xsi_set_current_line(70, ng0);

LAB65:    xsi_set_current_line(71, ng0);
    t26 = (t0 + 1928);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    t30 = ((char*)((ng3)));
    memset(t29, 0, 8);
    t31 = (t28 + 4);
    if (*((unsigned int *)t31) != 0)
        goto LAB67;

LAB66:    t32 = (t30 + 4);
    if (*((unsigned int *)t32) != 0)
        goto LAB67;

LAB70:    if (*((unsigned int *)t28) < *((unsigned int *)t30))
        goto LAB68;

LAB69:    t39 = (t29 + 4);
    t34 = *((unsigned int *)t39);
    t35 = (~(t34));
    t36 = *((unsigned int *)t29);
    t37 = (t36 & t35);
    t38 = (t37 != 0);
    if (t38 > 0)
        goto LAB71;

LAB72:    xsi_set_current_line(75, ng0);

LAB75:    xsi_set_current_line(76, ng0);
    t2 = (t0 + 1048U);
    t4 = *((char **)t2);
    memset(t8, 0, 8);
    t2 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t14 = *((unsigned int *)t4);
    t14 = (t14 & 1);
    if (*((unsigned int *)t2) != 0)
        goto LAB76;

LAB77:    t15 = 1;

LAB79:    t16 = (t15 <= 4);
    if (t16 == 1)
        goto LAB80;

LAB81:    *((unsigned int *)t8) = t14;

LAB78:    t11 = (t8 + 4);
    t20 = *((unsigned int *)t11);
    t21 = (~(t20));
    t22 = *((unsigned int *)t8);
    t23 = (t22 & t21);
    t24 = (t23 != 0);
    if (t24 > 0)
        goto LAB83;

LAB84:    xsi_set_current_line(77, ng0);

LAB86:    xsi_set_current_line(78, ng0);
    t2 = ((char*)((ng4)));
    t4 = (t0 + 2728);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);
    xsi_set_current_line(79, ng0);
    t2 = (t0 + 1928);
    t4 = (t2 + 56U);
    t10 = *((char **)t4);
    t11 = ((char*)((ng4)));
    memset(t8, 0, 8);
    xsi_vlog_unsigned_add(t8, 32, t10, 6, t11, 32);
    t12 = (t0 + 1928);
    xsi_vlogvar_assign_value(t12, t8, 0, 0, 6);

LAB85:
LAB73:    goto LAB64;

LAB67:    t33 = (t29 + 4);
    *((unsigned int *)t29) = 1;
    *((unsigned int *)t33) = 1;
    goto LAB69;

LAB68:    *((unsigned int *)t29) = 1;
    goto LAB69;

LAB71:    xsi_set_current_line(71, ng0);

LAB74:    xsi_set_current_line(72, ng0);
    t40 = ((char*)((ng4)));
    t41 = (t0 + 3368);
    xsi_vlogvar_assign_value(t41, t40, 0, 0, 1);
    xsi_set_current_line(73, ng0);
    t2 = (t0 + 1928);
    t4 = (t2 + 56U);
    t10 = *((char **)t4);
    t11 = ((char*)((ng4)));
    memset(t8, 0, 8);
    xsi_vlog_unsigned_add(t8, 32, t10, 6, t11, 32);
    t12 = (t0 + 1928);
    xsi_vlogvar_assign_value(t12, t8, 0, 0, 6);
    goto LAB73;

LAB76:    t10 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t10) = 1;
    goto LAB78;

LAB80:    t13 = (t13 >> 1);
    t17 = (t13 & 1);
    t14 = (t14 ^ t17);

LAB82:    t15 = (t15 + 1);
    goto LAB79;

LAB83:    xsi_set_current_line(76, ng0);
    t12 = ((char*)((ng4)));
    t18 = (t0 + 2248);
    xsi_vlogvar_assign_value(t18, t12, 0, 0, 1);
    goto LAB85;

}


extern void work_m_00087109872183081495_1338705563_init()
{
	static char *pe[] = {(void *)Initial_21_0,(void *)Always_34_1};
	xsi_register_didat("work_m_00087109872183081495_1338705563", "isim/lab3_2_isim_beh.exe.sim/work/m_00087109872183081495_1338705563.didat");
	xsi_register_executes(pe);
}
