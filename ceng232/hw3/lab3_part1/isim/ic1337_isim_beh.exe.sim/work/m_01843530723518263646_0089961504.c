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
static const char *ng0 = "/home/bs2020/e2521581/Desktop/emregecit2@github/4th-semester/ceng232/hw3/lab3_part1/lab3_1.v";



static void Always_28_0(char *t0)
{
    char t4[8];
    char t5[8];
    char t14[8];
    char t29[8];
    char t36[8];
    char t71[8];
    char t83[8];
    char t92[8];
    char t100[8];
    char *t1;
    char *t2;
    char *t3;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;
    char *t28;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    char *t35;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;
    char *t41;
    char *t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    char *t50;
    char *t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    char *t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    char *t70;
    char *t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    char *t78;
    char *t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    char *t84;
    char *t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    char *t91;
    char *t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    char *t99;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    char *t104;
    char *t105;
    char *t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    char *t114;
    char *t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    unsigned int t119;
    unsigned int t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t123;
    int t124;
    int t125;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    unsigned int t129;
    unsigned int t130;
    unsigned int t131;
    char *t132;

LAB0:    t1 = (t0 + 3640U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(28, ng0);
    t2 = (t0 + 4456);
    *((int *)t2) = 1;
    t3 = (t0 + 3672);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(29, ng0);

LAB5:    xsi_set_current_line(30, ng0);
    t6 = (t0 + 1208U);
    t7 = *((char **)t6);
    memset(t5, 0, 8);
    t6 = (t7 + 4);
    t8 = *((unsigned int *)t6);
    t9 = (~(t8));
    t10 = *((unsigned int *)t7);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t6) == 0)
        goto LAB6;

LAB8:    t13 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t13) = 1;

LAB9:    memset(t14, 0, 8);
    t15 = (t5 + 4);
    t16 = *((unsigned int *)t15);
    t17 = (~(t16));
    t18 = *((unsigned int *)t5);
    t19 = (t18 & t17);
    t20 = (t19 & 1U);
    if (t20 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t15) != 0)
        goto LAB12;

LAB13:    t22 = (t14 + 4);
    t23 = *((unsigned int *)t14);
    t24 = (!(t23));
    t25 = *((unsigned int *)t22);
    t26 = (t24 || t25);
    if (t26 > 0)
        goto LAB14;

LAB15:    memcpy(t36, t14, 8);

LAB16:    memset(t4, 0, 8);
    t64 = (t36 + 4);
    t65 = *((unsigned int *)t64);
    t66 = (~(t65));
    t67 = *((unsigned int *)t36);
    t68 = (t67 & t66);
    t69 = (t68 & 1U);
    if (t69 != 0)
        goto LAB27;

LAB25:    if (*((unsigned int *)t64) == 0)
        goto LAB24;

LAB26:    t70 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t70) = 1;

LAB27:    memset(t71, 0, 8);
    t72 = (t4 + 4);
    t73 = *((unsigned int *)t72);
    t74 = (~(t73));
    t75 = *((unsigned int *)t4);
    t76 = (t75 & t74);
    t77 = (t76 & 1U);
    if (t77 != 0)
        goto LAB28;

LAB29:    if (*((unsigned int *)t72) != 0)
        goto LAB30;

LAB31:    t79 = (t71 + 4);
    t80 = *((unsigned int *)t71);
    t81 = *((unsigned int *)t79);
    t82 = (t80 || t81);
    if (t82 > 0)
        goto LAB32;

LAB33:    memcpy(t100, t71, 8);

LAB34:    t132 = (t0 + 2568);
    xsi_vlogvar_wait_assign_value(t132, t100, 0, 0, 1, 0LL);
    xsi_set_current_line(31, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    memset(t14, 0, 8);
    t2 = (t3 + 4);
    t8 = *((unsigned int *)t2);
    t9 = (~(t8));
    t10 = *((unsigned int *)t3);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB46;

LAB47:    if (*((unsigned int *)t2) != 0)
        goto LAB48;

LAB49:    t7 = (t14 + 4);
    t16 = *((unsigned int *)t14);
    t17 = (!(t16));
    t18 = *((unsigned int *)t7);
    t19 = (t17 || t18);
    if (t19 > 0)
        goto LAB50;

LAB51:    memcpy(t71, t14, 8);

LAB52:    memset(t5, 0, 8);
    t50 = (t71 + 4);
    t65 = *((unsigned int *)t50);
    t66 = (~(t65));
    t67 = *((unsigned int *)t71);
    t68 = (t67 & t66);
    t69 = (t68 & 1U);
    if (t69 != 0)
        goto LAB67;

LAB65:    if (*((unsigned int *)t50) == 0)
        goto LAB64;

LAB66:    t51 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t51) = 1;

LAB67:    t64 = (t0 + 1048U);
    t70 = *((char **)t64);
    memset(t83, 0, 8);
    t64 = (t70 + 4);
    t73 = *((unsigned int *)t70);
    t74 = *((unsigned int *)t70);
    t74 = (t74 & 1);
    if (*((unsigned int *)t64) != 0)
        goto LAB68;

LAB69:    t75 = 1;

LAB71:    t76 = (t75 <= 0);
    if (t76 == 1)
        goto LAB72;

LAB73:    *((unsigned int *)t83) = t74;

LAB70:    t80 = *((unsigned int *)t5);
    t81 = *((unsigned int *)t83);
    t82 = (t80 ^ t81);
    *((unsigned int *)t92) = t82;
    t78 = (t5 + 4);
    t79 = (t83 + 4);
    t84 = (t92 + 4);
    t86 = *((unsigned int *)t78);
    t87 = *((unsigned int *)t79);
    t88 = (t86 | t87);
    *((unsigned int *)t84) = t88;
    t89 = *((unsigned int *)t84);
    t90 = (t89 != 0);
    if (t90 == 1)
        goto LAB75;

LAB76:
LAB77:    memset(t4, 0, 8);
    t85 = (t92 + 4);
    t96 = *((unsigned int *)t85);
    t97 = (~(t96));
    t98 = *((unsigned int *)t92);
    t101 = (t98 & t97);
    t102 = (t101 & 1U);
    if (t102 != 0)
        goto LAB81;

LAB79:    if (*((unsigned int *)t85) == 0)
        goto LAB78;

LAB80:    t91 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t91) = 1;

LAB81:    t93 = (t0 + 2728);
    xsi_vlogvar_wait_assign_value(t93, t4, 0, 0, 1, 0LL);
    goto LAB2;

LAB6:    *((unsigned int *)t5) = 1;
    goto LAB9;

LAB10:    *((unsigned int *)t14) = 1;
    goto LAB13;

LAB12:    t21 = (t14 + 4);
    *((unsigned int *)t14) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB13;

LAB14:    t27 = (t0 + 1048U);
    t28 = *((char **)t27);
    memset(t29, 0, 8);
    t27 = (t28 + 4);
    t30 = *((unsigned int *)t27);
    t31 = (~(t30));
    t32 = *((unsigned int *)t28);
    t33 = (t32 & t31);
    t34 = (t33 & 1U);
    if (t34 != 0)
        goto LAB17;

LAB18:    if (*((unsigned int *)t27) != 0)
        goto LAB19;

LAB20:    t37 = *((unsigned int *)t14);
    t38 = *((unsigned int *)t29);
    t39 = (t37 | t38);
    *((unsigned int *)t36) = t39;
    t40 = (t14 + 4);
    t41 = (t29 + 4);
    t42 = (t36 + 4);
    t43 = *((unsigned int *)t40);
    t44 = *((unsigned int *)t41);
    t45 = (t43 | t44);
    *((unsigned int *)t42) = t45;
    t46 = *((unsigned int *)t42);
    t47 = (t46 != 0);
    if (t47 == 1)
        goto LAB21;

LAB22:
LAB23:    goto LAB16;

LAB17:    *((unsigned int *)t29) = 1;
    goto LAB20;

LAB19:    t35 = (t29 + 4);
    *((unsigned int *)t29) = 1;
    *((unsigned int *)t35) = 1;
    goto LAB20;

LAB21:    t48 = *((unsigned int *)t36);
    t49 = *((unsigned int *)t42);
    *((unsigned int *)t36) = (t48 | t49);
    t50 = (t14 + 4);
    t51 = (t29 + 4);
    t52 = *((unsigned int *)t50);
    t53 = (~(t52));
    t54 = *((unsigned int *)t14);
    t55 = (t54 & t53);
    t56 = *((unsigned int *)t51);
    t57 = (~(t56));
    t58 = *((unsigned int *)t29);
    t59 = (t58 & t57);
    t60 = (~(t55));
    t61 = (~(t59));
    t62 = *((unsigned int *)t42);
    *((unsigned int *)t42) = (t62 & t60);
    t63 = *((unsigned int *)t42);
    *((unsigned int *)t42) = (t63 & t61);
    goto LAB23;

LAB24:    *((unsigned int *)t4) = 1;
    goto LAB27;

LAB28:    *((unsigned int *)t71) = 1;
    goto LAB31;

LAB30:    t78 = (t71 + 4);
    *((unsigned int *)t71) = 1;
    *((unsigned int *)t78) = 1;
    goto LAB31;

LAB32:    t84 = (t0 + 1368U);
    t85 = *((char **)t84);
    memset(t83, 0, 8);
    t84 = (t85 + 4);
    t86 = *((unsigned int *)t84);
    t87 = (~(t86));
    t88 = *((unsigned int *)t85);
    t89 = (t88 & t87);
    t90 = (t89 & 1U);
    if (t90 != 0)
        goto LAB38;

LAB36:    if (*((unsigned int *)t84) == 0)
        goto LAB35;

LAB37:    t91 = (t83 + 4);
    *((unsigned int *)t83) = 1;
    *((unsigned int *)t91) = 1;

LAB38:    memset(t92, 0, 8);
    t93 = (t83 + 4);
    t94 = *((unsigned int *)t93);
    t95 = (~(t94));
    t96 = *((unsigned int *)t83);
    t97 = (t96 & t95);
    t98 = (t97 & 1U);
    if (t98 != 0)
        goto LAB39;

LAB40:    if (*((unsigned int *)t93) != 0)
        goto LAB41;

LAB42:    t101 = *((unsigned int *)t71);
    t102 = *((unsigned int *)t92);
    t103 = (t101 & t102);
    *((unsigned int *)t100) = t103;
    t104 = (t71 + 4);
    t105 = (t92 + 4);
    t106 = (t100 + 4);
    t107 = *((unsigned int *)t104);
    t108 = *((unsigned int *)t105);
    t109 = (t107 | t108);
    *((unsigned int *)t106) = t109;
    t110 = *((unsigned int *)t106);
    t111 = (t110 != 0);
    if (t111 == 1)
        goto LAB43;

LAB44:
LAB45:    goto LAB34;

LAB35:    *((unsigned int *)t83) = 1;
    goto LAB38;

LAB39:    *((unsigned int *)t92) = 1;
    goto LAB42;

LAB41:    t99 = (t92 + 4);
    *((unsigned int *)t92) = 1;
    *((unsigned int *)t99) = 1;
    goto LAB42;

LAB43:    t112 = *((unsigned int *)t100);
    t113 = *((unsigned int *)t106);
    *((unsigned int *)t100) = (t112 | t113);
    t114 = (t71 + 4);
    t115 = (t92 + 4);
    t116 = *((unsigned int *)t71);
    t117 = (~(t116));
    t118 = *((unsigned int *)t114);
    t119 = (~(t118));
    t120 = *((unsigned int *)t92);
    t121 = (~(t120));
    t122 = *((unsigned int *)t115);
    t123 = (~(t122));
    t124 = (t117 & t119);
    t125 = (t121 & t123);
    t126 = (~(t124));
    t127 = (~(t125));
    t128 = *((unsigned int *)t106);
    *((unsigned int *)t106) = (t128 & t126);
    t129 = *((unsigned int *)t106);
    *((unsigned int *)t106) = (t129 & t127);
    t130 = *((unsigned int *)t100);
    *((unsigned int *)t100) = (t130 & t126);
    t131 = *((unsigned int *)t100);
    *((unsigned int *)t100) = (t131 & t127);
    goto LAB45;

LAB46:    *((unsigned int *)t14) = 1;
    goto LAB49;

LAB48:    t6 = (t14 + 4);
    *((unsigned int *)t14) = 1;
    *((unsigned int *)t6) = 1;
    goto LAB49;

LAB50:    t13 = (t0 + 1208U);
    t15 = *((char **)t13);
    memset(t29, 0, 8);
    t13 = (t15 + 4);
    t20 = *((unsigned int *)t13);
    t23 = (~(t20));
    t24 = *((unsigned int *)t15);
    t25 = (t24 & t23);
    t26 = (t25 & 1U);
    if (t26 != 0)
        goto LAB56;

LAB54:    if (*((unsigned int *)t13) == 0)
        goto LAB53;

LAB55:    t21 = (t29 + 4);
    *((unsigned int *)t29) = 1;
    *((unsigned int *)t21) = 1;

LAB56:    memset(t36, 0, 8);
    t22 = (t29 + 4);
    t30 = *((unsigned int *)t22);
    t31 = (~(t30));
    t32 = *((unsigned int *)t29);
    t33 = (t32 & t31);
    t34 = (t33 & 1U);
    if (t34 != 0)
        goto LAB57;

LAB58:    if (*((unsigned int *)t22) != 0)
        goto LAB59;

LAB60:    t37 = *((unsigned int *)t14);
    t38 = *((unsigned int *)t36);
    t39 = (t37 | t38);
    *((unsigned int *)t71) = t39;
    t28 = (t14 + 4);
    t35 = (t36 + 4);
    t40 = (t71 + 4);
    t43 = *((unsigned int *)t28);
    t44 = *((unsigned int *)t35);
    t45 = (t43 | t44);
    *((unsigned int *)t40) = t45;
    t46 = *((unsigned int *)t40);
    t47 = (t46 != 0);
    if (t47 == 1)
        goto LAB61;

LAB62:
LAB63:    goto LAB52;

LAB53:    *((unsigned int *)t29) = 1;
    goto LAB56;

LAB57:    *((unsigned int *)t36) = 1;
    goto LAB60;

LAB59:    t27 = (t36 + 4);
    *((unsigned int *)t36) = 1;
    *((unsigned int *)t27) = 1;
    goto LAB60;

LAB61:    t48 = *((unsigned int *)t71);
    t49 = *((unsigned int *)t40);
    *((unsigned int *)t71) = (t48 | t49);
    t41 = (t14 + 4);
    t42 = (t36 + 4);
    t52 = *((unsigned int *)t41);
    t53 = (~(t52));
    t54 = *((unsigned int *)t14);
    t55 = (t54 & t53);
    t56 = *((unsigned int *)t42);
    t57 = (~(t56));
    t58 = *((unsigned int *)t36);
    t59 = (t58 & t57);
    t60 = (~(t55));
    t61 = (~(t59));
    t62 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t62 & t60);
    t63 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t63 & t61);
    goto LAB63;

LAB64:    *((unsigned int *)t5) = 1;
    goto LAB67;

LAB68:    t72 = (t83 + 4);
    *((unsigned int *)t83) = 1;
    *((unsigned int *)t72) = 1;
    goto LAB70;

LAB72:    t73 = (t73 >> 1);
    t77 = (t73 & 1);
    t74 = (t74 ^ t77);

LAB74:    t75 = (t75 + 1);
    goto LAB71;

LAB75:    t94 = *((unsigned int *)t92);
    t95 = *((unsigned int *)t84);
    *((unsigned int *)t92) = (t94 | t95);
    goto LAB77;

LAB78:    *((unsigned int *)t4) = 1;
    goto LAB81;

}

static void Cont_35_1(char *t0)
{
    char t4[8];
    char t12[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    char *t36;
    unsigned int t37;
    unsigned int t38;
    char *t39;

LAB0:    t1 = (t0 + 3888U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(35, ng0);
    t2 = (t0 + 1688U);
    t3 = *((char **)t2);
    t2 = (t0 + 1848U);
    t5 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t5 + 4);
    t6 = *((unsigned int *)t5);
    t7 = *((unsigned int *)t5);
    t7 = (t7 & 1);
    if (*((unsigned int *)t2) != 0)
        goto LAB4;

LAB5:    t9 = 1;

LAB7:    t10 = (t9 <= 0);
    if (t10 == 1)
        goto LAB8;

LAB9:    *((unsigned int *)t4) = t7;

LAB6:    t13 = *((unsigned int *)t3);
    t14 = *((unsigned int *)t4);
    t15 = (t13 ^ t14);
    *((unsigned int *)t12) = t15;
    t16 = (t3 + 4);
    t17 = (t4 + 4);
    t18 = (t12 + 4);
    t19 = *((unsigned int *)t16);
    t20 = *((unsigned int *)t17);
    t21 = (t19 | t20);
    *((unsigned int *)t18) = t21;
    t22 = *((unsigned int *)t18);
    t23 = (t22 != 0);
    if (t23 == 1)
        goto LAB11;

LAB12:
LAB13:    t26 = (t0 + 4568);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    memset(t30, 0, 8);
    t31 = 1U;
    t32 = t31;
    t33 = (t12 + 4);
    t34 = *((unsigned int *)t12);
    t31 = (t31 & t34);
    t35 = *((unsigned int *)t33);
    t32 = (t32 & t35);
    t36 = (t30 + 4);
    t37 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t37 | t31);
    t38 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t38 | t32);
    xsi_driver_vfirst_trans(t26, 0, 0);
    t39 = (t0 + 4472);
    *((int *)t39) = 1;

LAB1:    return;
LAB4:    t8 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t8) = 1;
    goto LAB6;

LAB8:    t6 = (t6 >> 1);
    t11 = (t6 & 1);
    t7 = (t7 ^ t11);

LAB10:    t9 = (t9 + 1);
    goto LAB7;

LAB11:    t24 = *((unsigned int *)t12);
    t25 = *((unsigned int *)t18);
    *((unsigned int *)t12) = (t24 | t25);
    goto LAB13;

}

static void implSig1_execute(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    unsigned int t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;

LAB0:    t1 = (t0 + 4136U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 1368U);
    t4 = *((char **)t2);
    memset(t3, 0, 8);
    t2 = (t4 + 4);
    t5 = *((unsigned int *)t2);
    t6 = (~(t5));
    t7 = *((unsigned int *)t4);
    t8 = (t7 & t6);
    t9 = (t8 & 1U);
    if (t9 != 0)
        goto LAB7;

LAB5:    if (*((unsigned int *)t2) == 0)
        goto LAB4;

LAB6:    t10 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t10) = 1;

LAB7:    t11 = (t0 + 4632);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    memset(t15, 0, 8);
    t16 = 1U;
    t17 = t16;
    t18 = (t3 + 4);
    t19 = *((unsigned int *)t3);
    t16 = (t16 & t19);
    t20 = *((unsigned int *)t18);
    t17 = (t17 & t20);
    t21 = (t15 + 4);
    t22 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t22 | t16);
    t23 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t23 | t17);
    xsi_driver_vfirst_trans(t11, 0, 0);
    t24 = (t0 + 4488);
    *((int *)t24) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t3) = 1;
    goto LAB7;

}


extern void work_m_01843530723518263646_0089961504_init()
{
	static char *pe[] = {(void *)Always_28_0,(void *)Cont_35_1,(void *)implSig1_execute};
	xsi_register_didat("work_m_01843530723518263646_0089961504", "isim/ic1337_isim_beh.exe.sim/work/m_01843530723518263646_0089961504.didat");
	xsi_register_executes(pe);
}
