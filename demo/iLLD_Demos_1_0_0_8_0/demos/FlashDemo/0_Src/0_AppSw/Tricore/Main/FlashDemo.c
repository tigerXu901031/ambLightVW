/**
 * \file FlashDemo.c
 * \brief Flash erase & program Demo
 *
 * \version iLLD_Demos_1_0_0_8_0
 * \copyright Copyright (c) 2014 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include <stdio.h>
#include <string.h>
#include "Cpu0_Main.h"
#include <Cpu/Std/IfxCpu.h>
#include "Ifx_Assert.h"
#include "FlashDemo.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/
#define FLASHDEMO_PFLASH_PAGE_LENGTH 0x20          /**< \brief P Flash Page Length */

#define FLASHDEMO_PFLASH_SECTOR_NO   22            /**< \brief P Flash Sector to be erased & Programmed */
#define FLASHDEMO_PFLASH_START_PAGE  0             /**< \brief P Flash Programming starts from this page */
#define FLASHDEMO_PFLASH_NO_OF_PAGES 5             /**< \brief P Flash - No of pages to be programmed */

#define FLASHDEMO_DFLASH_SECTOR_NO   0             /**< \brief D Flash Sector to be erased & Programmed */
#define FLASHDEMO_DFLASH_START_PAGE  0             /**< \brief D Flash Programming starts from this page */
#define FLASHDEMO_DFLASH_NO_OF_PAGES 16            /**< \brief D Flash - No of pages to be programmed */

#define FLASHDEMO_RELOC_START_ADDR   (0xC0000000U) /**< \brief Program & Erase routines relocation address */

/** \brief Length of Program & Erase routines
 */
#define FLASHDEMO_ERASESECTOR_LEN    (100)
#define FLASHDEMO_WAITUNBUSY_LEN     (100)
#define FLASHDEMO_ENTERPAGEMODE_LEN  (100)
#define FLASHDEMO_LOADPAGE2X32_LEN   (100)
#define FLASHDEMO_WRITEPAGE_LEN      (100)
#define FLASHDEMO_PFLASHERASE_LEN    (0x100)
#define FLASHDEMO_PFLASHPROGRAM_LEN  (0x10C)

/** \brief Program & Erase routines relocation length */
#define FLASHDEMO_RELOC_LENGTH                                  \
    (FLASHDEMO_ERASESECTOR_LEN + FLASHDEMO_WAITUNBUSY_LEN +     \
     FLASHDEMO_ENTERPAGEMODE_LEN + FLASHDEMO_LOADPAGE2X32_LEN + \
     FLASHDEMO_WRITEPAGE_LEN + FLASHDEMO_PFLASHERASE_LEN +      \
     FLASHDEMO_PFLASHPROGRAM_LEN)

/** \brief Start addresses of Program & Erase routines
 */
#define FLASHDEMO_ERASESECTOR_ADDR   (FLASHDEMO_RELOC_START_ADDR)
#define FLASHDEMO_WAITUNBUSY_ADDR    (FLASHDEMO_ERASESECTOR_ADDR + FLASHDEMO_ERASESECTOR_LEN)
#define FLASHDEMO_ENTERPAGEMODE_ADDR (FLASHDEMO_WAITUNBUSY_ADDR + FLASHDEMO_WAITUNBUSY_LEN)
#define FLASHDEMO_LOADPAGE2X32_ADDR  (FLASHDEMO_ENTERPAGEMODE_ADDR + FLASHDEMO_ENTERPAGEMODE_LEN)
#define FLASHDEMO_WRITEPAGE_ADDR     (FLASHDEMO_LOADPAGE2X32_ADDR + FLASHDEMO_LOADPAGE2X32_LEN)
#define FLASHDEMO_PFLASHERASE_ADDR   (FLASHDEMO_WRITEPAGE_ADDR + FLASHDEMO_WRITEPAGE_LEN)
#define FLASHDEMO_PFLASHPROGRAM_ADDR (FLASHDEMO_PFLASHERASE_ADDR + FLASHDEMO_PFLASHERASE_LEN)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/
App_Pflash g_Pflash; /**< \brief PFlash global data */
App_Dflash g_Dflash; /**< \brief DFlash global data */

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
static void PFlashErase(uint32 flash, uint32 sector_addr);
static void PFlashProgram(uint32 flash, uint32 sector_addr, uint32 start_page, uint32 no_of_pages);
/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/
/** \brief copyFlashRoutinesToPspr
 *
 * This function copies the erase and program routines to PSPR memory
 */
static void copyFlashRoutinesToPspr(void)
{
    /*
     * Copy the below Flash routines to PSPR memory & assign a function pointer
     * IfxFlash_eraseSector, IfxFlash_waitUnbusy, IfxFlash_enterPageMode, IfxFlash_loadPage2X32, IfxFlash_writePage
     * PFlashErase, PFlashProgram
     */
    memcpy((void *)FLASHDEMO_ERASESECTOR_ADDR, (const void *)IfxFlash_eraseSector, FLASHDEMO_ERASESECTOR_LEN);
    g_Pflash.command.eraseSector = (void *)FLASHDEMO_RELOC_START_ADDR;

    memcpy((void *)FLASHDEMO_WAITUNBUSY_ADDR, (const void *)IfxFlash_waitUnbusy, FLASHDEMO_WAITUNBUSY_LEN);
    g_Pflash.command.waitUnbusy = (void *)FLASHDEMO_WAITUNBUSY_ADDR;

    memcpy((void *)FLASHDEMO_ENTERPAGEMODE_ADDR, (const void *)IfxFlash_enterPageMode, FLASHDEMO_ENTERPAGEMODE_LEN);
    g_Pflash.command.enterPageMode = (void *)FLASHDEMO_ENTERPAGEMODE_ADDR;

    memcpy((void *)FLASHDEMO_LOADPAGE2X32_ADDR, (const void *)IfxFlash_loadPage2X32, FLASHDEMO_LOADPAGE2X32_LEN);
    g_Pflash.command.loadPage2X32 = (void *)FLASHDEMO_LOADPAGE2X32_ADDR;

    memcpy((void *)FLASHDEMO_WRITEPAGE_ADDR, (const void *)IfxFlash_writePage, FLASHDEMO_WRITEPAGE_LEN);
    g_Pflash.command.writePage = (void *)FLASHDEMO_WRITEPAGE_ADDR;

    memcpy((void *)FLASHDEMO_PFLASHERASE_ADDR, (const void *)PFlashErase, FLASHDEMO_PFLASHERASE_LEN);
    g_Pflash.command.pFlashErase = (void *)FLASHDEMO_PFLASHERASE_ADDR;

    memcpy((void *)FLASHDEMO_PFLASHPROGRAM_ADDR, (const void *)PFlashProgram, FLASHDEMO_PFLASHPROGRAM_LEN);
    g_Pflash.command.pFlashProgram = (void *)FLASHDEMO_PFLASHPROGRAM_ADDR;
}


/** \brief PFlashErase
 *
 * This function will erase the P-Flash Sector
 * Note: This function shouldn't be executed from Flash it is trying to erase.
 * Recommended to execute the routine from PSPR memory
 */
static void PFlashErase(uint32 flash, uint32 sector_addr)
{
    uint16 endinitSfty_pw;
    endinitSfty_pw = IfxScuWdt_getSafetyWatchdogPasswordInline();

    /* Erase the sector */
    IfxScuWdt_clearSafetyEndinitInline(endinitSfty_pw);
    g_Pflash.command.eraseSector(sector_addr);
    IfxScuWdt_setSafetyEndinitInline(endinitSfty_pw);

    /* wait until unbusy */
    g_Pflash.command.waitUnbusy(flash, g_Pflash.flashType);
}


/** \brief PFlashProgram
 *
 * This function will program the P-Flash Sector
 * Note: This function shouldn't be executed from Flash it is trying to program.
 * Recommended to execute the routine from PSPR memory
 */
static void PFlashProgram(uint32 flash, uint32 sector_addr, uint32 start_page, uint32 no_of_pages)
{
    uint32 offset;
    uint32 page;
    uint16 endinitSfty_pw;
    endinitSfty_pw = IfxScuWdt_getSafetyWatchdogPasswordInline();

    /* program the given no of pages */
    for (page = start_page; page < no_of_pages; ++page)
    {
        uint32 pageAddr = sector_addr + page * FLASHDEMO_PFLASH_PAGE_LENGTH;
        g_Pflash.command.enterPageMode(pageAddr);

        /* wait until unbusy */
        g_Pflash.command.waitUnbusy(flash, g_Pflash.flashType);

        /* write 32 bytes (8 doublewords) into assembly buffer */
        for (offset = 0; offset < FLASHDEMO_PFLASH_PAGE_LENGTH; offset += 8)
        {
            g_Pflash.command.loadPage2X32(pageAddr, pageAddr, offset);
        }

        /* write page */
        IfxScuWdt_clearSafetyEndinitInline(endinitSfty_pw);
        g_Pflash.command.writePage(pageAddr);
        IfxScuWdt_setSafetyEndinitInline(endinitSfty_pw);

        /* wait until unbusy */
        g_Pflash.command.waitUnbusy(flash, g_Pflash.flashType);
    }
}


/** \brief P-Flash Demo
 *
 * This function is called from the run to demo the P-Flash Erase & Program functionality
 */
static void PFlashDemo(void)
{
    uint32  errors      = 0;
    uint32  offset;
    uint32  page        = 0;
    uint32  flash       = 0;
    uint32  sector_addr = IfxFlash_pFlashTableLog[g_Pflash.sector].start;

    /* disable interrupts */
    boolean interruptState = IfxCpu_disableInterrupts();

    /* Copy the erase and program routines to PSPR memory */
    copyFlashRoutinesToPspr();

    /* erase & program flash (execute from relocated memory)*/
    g_Pflash.command.pFlashErase(flash, sector_addr);
    g_Pflash.command.pFlashProgram(flash, sector_addr, g_Pflash.startPage, g_Pflash.numberOfPages);

    /* enable interrupts again */
    IfxCpu_restoreInterrupts(interruptState);

    /* Verify the programmed data */
    for (page = g_Pflash.startPage; page < g_Pflash.numberOfPages; ++page)
    {
        uint32          pageAddr = sector_addr + page * FLASHDEMO_PFLASH_PAGE_LENGTH;
        volatile uint8 *addr     = (uint8 *)pageAddr;

        for (offset = 0; offset < FLASHDEMO_PFLASH_PAGE_LENGTH; offset += 8)
        {
            if (!((pageAddr == *((uint32 *)(addr + offset))) &&
                  (addr[offset + 4] == offset)))
            {
                errors++;
            }
        }
    }

    IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, errors == 0);

    if (errors)
    {
        printf("ERROR: error while P-Flash erase / program\n");
    }
    else
    {
        printf("OK: P-Flash checks passed\n");
    }
}


/** \brief D-Flash Demo
 *
 * This function is called from the run to demo the D-Flash Erase & Program functionality
 */
static void DFlashDemo(void)
{
    uint32 errors = 0;
    uint16 endinitSfty_pw;
    uint32 offset;
    uint32 page;
    uint32 flash       = 0;
    uint32 sector_addr = IfxFlash_dFlashTableEepLog[g_Dflash.sector].start;

    endinitSfty_pw = IfxScuWdt_getSafetyWatchdogPassword();

    /* erase program flash */
    IfxScuWdt_clearSafetyEndinit(endinitSfty_pw);
    IfxFlash_eraseSector(sector_addr);
    IfxScuWdt_setSafetyEndinit(endinitSfty_pw);

    /* wait until unbusy */
    IfxFlash_waitUnbusy(flash, g_Dflash.flashType);

    /* program the given no of pages */
    for (page = g_Dflash.startPage; page < g_Dflash.numberOfPages; ++page)
    {
        uint32 pageAddr = sector_addr + page * IFXFLASH_DFLASH_PAGE_LENGTH;
        errors = IfxFlash_enterPageMode(pageAddr);

        /* wait until unbusy */
        IfxFlash_waitUnbusy(flash, g_Dflash.flashType);

        IfxFlash_loadPage2X32(pageAddr, pageAddr, page);
        /* write page */
        IfxScuWdt_clearSafetyEndinit(endinitSfty_pw);
        IfxFlash_writePage(pageAddr);
        IfxScuWdt_setSafetyEndinit(endinitSfty_pw);

        /* wait until unbusy */
        IfxFlash_waitUnbusy(flash, g_Dflash.flashType);
    }

    /* Verify the programmed data */
    for (page = g_Dflash.startPage; page < g_Dflash.numberOfPages; ++page)
    {
        uint32          pageAddr = sector_addr + page * IFXFLASH_DFLASH_PAGE_LENGTH;
        volatile uint8 *addr     = (uint8 *)pageAddr;

        for (offset = 0; offset < IFXFLASH_DFLASH_PAGE_LENGTH; offset += 8)
        {
            if (!((pageAddr == *((uint32 *)(addr))) &&
                  (addr[4] == page)))
            {
                errors++;
            }
        }
    }

    IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, errors == 0);

    if (errors)
    {
        printf("ERROR: error while D-Flash erase / program\n");
    }
    else
    {
        printf("OK: D-Flash checks passed\n");
    }
}


/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
void IfxFlashDemo_init(void)
{
    /* Initialise the P Flash global data */
    g_Pflash.sector        = FLASHDEMO_PFLASH_SECTOR_NO;
    g_Pflash.startPage     = FLASHDEMO_PFLASH_START_PAGE;
    g_Pflash.numberOfPages = FLASHDEMO_PFLASH_NO_OF_PAGES;
    g_Pflash.flashType     = IfxFlash_FlashType_P0;

    /* Initialise the D Flash global data */
    g_Dflash.sector        = FLASHDEMO_DFLASH_SECTOR_NO;
    g_Dflash.startPage     = FLASHDEMO_DFLASH_START_PAGE;
    g_Dflash.numberOfPages = FLASHDEMO_DFLASH_NO_OF_PAGES;
    g_Dflash.flashType     = IfxFlash_FlashType_D0;
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void IfxFlashDemo_run(void)
{
    PFlashDemo();
    DFlashDemo();
}
