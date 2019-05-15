cmake_minimum_required(VERSION 3.10)
project(hardware-sim C)

set(CMAKE_C_STANDARD 99)

find_package(BISON)
find_package(FLEX)

FLEX_TARGET(HardwareSimLexer src/hardware-sim.l  src/lex.yy.c)
BISON_TARGET(HardwareSimParser src/hardware-sim.y src/hardware-sim.tab.c DEFINES_FILE src/hardware-sim.tab.h)
ADD_FLEX_BISON_DEPENDENCY(HardwareSimLexer HardwareSimParser)

set(HARDWARE_SIM_SOURCES
        src/ast/module.c
        src/ast/module_body.c
        src/ast/module_input.c
        src/ast/module_output.c
        src/ast/module_internal.c
        src/ast/module_wire.c
        src/ast/module_instance.c
        src/ast/actual.c
        src/ast/positional_actual.c
        src/ast/keyword_actual.c
        src/ast/ast_helper.c
        ${BISON_HardwareSimParser_OUTPUTS}
        ${FLEX_HardwareSimLexer_OUTPUTS}
)

add_executable(hardware-sim ${HARDWARE_SIM_SOURCES})