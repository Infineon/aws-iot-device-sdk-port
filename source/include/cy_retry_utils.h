/*
 * Copyright 2022, Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
 *
 * This software, including source code, documentation and related
 * materials ("Software") is owned by Cypress Semiconductor Corporation
 * or one of its affiliates ("Cypress") and is protected by and subject to
 * worldwide patent protection (United States and foreign),
 * United States copyright laws and international treaty provisions.
 * Therefore, you may use this Software only as provided in the license
 * agreement accompanying the software package from which you
 * obtained this Software ("EULA").
 * If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
 * non-transferable license to copy, modify, and compile the Software
 * source code solely for use in connection with Cypress's
 * integrated circuit products.  Any reproduction, modification, translation,
 * compilation, or representation of this Software except as specified
 * above is prohibited without the express written permission of Cypress.
 *
 * Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
 * reserves the right to make changes to the Software without notice. Cypress
 * does not assume any liability arising out of the application or use of the
 * Software or any product or circuit described in the Software. Cypress does
 * not authorize its products for use in any products where a malfunction or
 * failure of the Cypress product may reasonably be expected to result in
 * significant property damage, injury or death ("High Risk Product"). By
 * including Cypress's product in a High Risk Product, the manufacturer
 * of such system or application assumes all risk of such use and in doing
 * so agrees to indemnify Cypress against all liability.
 */

/**
 * @file cy_retry_utils.h
 * Declaration of the exponential backoff retry logic utility functions and constants.
 */

#ifndef CY_RETRY_UTILS_H_
#define CY_RETRY_UTILS_H_

/* Standard include. */
#include <stdint.h>

/**
 * @brief Max number of retry attempts. Set this value to 0 if the client must
 * retry forever.
 */
#define MAX_RETRY_ATTEMPTS               4U

/**
 * @brief Initial fixed backoff value in seconds between two successive
 * retries. A random jitter value is added to every backoff value.
 */
#define INITIAL_RETRY_BACKOFF_SECONDS    1U

/**
 * @brief Max backoff value in seconds.
 */
#define MAX_RETRY_BACKOFF_SECONDS        128U

/**
 * @brief Max jitter value in seconds.
 */
#define MAX_JITTER_VALUE_SECONDS         5U

/**
 * @brief Status for @ref RetryUtils_BackoffAndSleep.
 */
typedef enum RetryUtilsStatus
{
    RetryUtilsSuccess = 0,     /**< @brief The function returned successfully after sleeping. */
    RetryUtilsRetriesExhausted /**< @brief The function exhausted all retry attempts. */
} RetryUtilsStatus_t;

/**
 * @brief Represents parameters required for retry logic.
 */
typedef struct RetryUtilsParams
{
    /**
     * @brief The cumulative count of backoff delay cycles completed
     * for retries.
     */
    uint32_t attemptsDone;

    /**
     * @brief The max jitter value for backoff time in retry attempt.
     */
    uint32_t nextJitterMax;
} RetryUtilsParams_t;


/**
 * @brief Resets the retry timeout value and number of attempts.
 * This function must be called by the application before a new retry attempt.
 *
 * @param[in, out] pRetryParams Structure containing attempts done and timeout
 * value.
 */
/* @[define_retryutils_paramsreset] */
void RetryUtils_ParamsReset( RetryUtilsParams_t * pRetryParams );
/* @[define_retryutils_paramsreset] */

/**
 * @brief Simple platform specific exponential backoff function. The application
 * must use this function between retry failures to add exponential delay.
 * This function will block the calling task for the current timeout value.
 *
 * @param[in, out] pRetryParams Structure containing retry parameters.
 *
 * @return #RetryUtilsSuccess after a successful sleep, #RetryUtilsRetriesExhausted
 * when all attempts are exhausted.
 */
/* @[define_retryutils_backoffandsleep] */
RetryUtilsStatus_t RetryUtils_BackoffAndSleep( RetryUtilsParams_t * pRetryParams );
/* @[define_retryutils_backoffandsleep] */

#endif /* ifndef CY_RETRY_UTILS_H_ */
