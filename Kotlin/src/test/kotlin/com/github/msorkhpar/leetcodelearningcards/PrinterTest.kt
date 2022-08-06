package com.github.msorkhpar.leetcodelearningcards

import com.github.stefanbirkner.systemlambda.SystemLambda.tapSystemOut
import com.github.stefanbirkner.systemlambda.SystemLambda.withTextFromSystemIn
import org.junit.jupiter.api.Assertions.*
import org.junit.jupiter.api.Test


internal class PrinterTest {
    @Test
    fun `main method should return a proper greeting`() {
        withTextFromSystemIn("Mo")
            .execute {
                val output = tapSystemOut {
                    main()
                }
                assertEquals("Hello Mo!", output.trim())
            }

    }
}