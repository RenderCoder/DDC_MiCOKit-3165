set remotetimeout 20
shell ./MiCoder/cmd/OSX/dash -c "trap \\"\\" 2;"./MiCoder/OpenOCD/OSX/openocd_mico" -f .//makefiles/OpenOCD/interface/jlink_swd.cfg -f .//makefiles/OpenOCD/stm32f4x/stm32f4x.cfg -f .//makefiles/OpenOCD/stm32f4x/stm32f4x_gdb_jtag.cfg -l build/openocd_log.txt &"
