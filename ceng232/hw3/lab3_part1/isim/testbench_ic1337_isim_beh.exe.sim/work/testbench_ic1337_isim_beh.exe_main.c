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

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    work_m_14086776074847075637_3983292432_init();
    work_m_01843530723518263646_0089961504_init();
    work_m_15876073782970355546_0976654022_init();
    work_m_11491833963429943931_2073120511_init();


    xsi_register_tops("work_m_15876073782970355546_0976654022");
    xsi_register_tops("work_m_11491833963429943931_2073120511");


    return xsi_run_simulation(argc, argv);

}
