#!/usr/bin/env bash

set -u  # error on undefined vars

CXX="C:/msys64/mingw64/bin/g++.exe"
CXXFLAGS="-std=c++20 -g"
TEST_DIR="tests"
BUILD_DIR="tests/bin"

mkdir -p "$BUILD_DIR"

echo "=============================="
echo " Building & Running Tests"
echo "=============================="
echo

TOTAL=0
PASSED=0
FAILED=0

run_test() {
    local test_file="$1"
    shift
    local deps=("$@")
    
    ((TOTAL++))
    
    test_name=$(basename "$test_file" .test.cc)
    exe="$BUILD_DIR/$test_name.exe"
    
    echo "🔨 Compiling $test_name..."
    
    $CXX $CXXFLAGS \
        "$test_file" \
        "${deps[@]}" \
        -o "$exe" 2>&1
    
    if [[ $? -ne 0 ]]; then
        echo "❌ COMPILE FAILED: $test_name"
        echo
        ((FAILED++))
        return 1
    fi
    
    echo "▶ Running $test_name..."
    "$exe"
    result=$?
    
    if [[ $result -eq 0 ]]; then
        echo "✅ PASS: $test_name"
        ((PASSED++))
    else
        echo "❌ FAIL: $test_name (exit code $result)"
        ((FAILED++))
    fi
    
    echo
}

# =============================================================================
# TEST DEFINITIONS
# Each test specifies its own source file dependencies
# Format: run_test "tests/name.test.cc" "source1.cc" "source2.cc" ...
# =============================================================================

# Enums test
run_test "tests/enums.test.cc" \
    "pokemon/constants/enums.cc"

# Type matchups test
run_test "tests/type-matchups.test.cc" \
    "pokemon/constants/enums.cc"

# Mods test
run_test "tests/mods.test.cc" \
    "pokemon/stats/mods/mods.cc"

# Stats test
run_test "tests/stats.test.cc" \
    "pokemon/stats/stats.cc" \
    "pokemon/stats/mods/mods.cc"

# Moves test
run_test "tests/moves.test.cc" \
    "pokemon/moves/move.cc" \
    "pokemon/constants/enums.cc" \
    "pokemon/effects/effects.cc" \
    "pokemon/effects/bind/bind.cc" \
    "pokemon/effects/charge/charge.cc" \
    "pokemon/effects/drain/drain.cc" \
    "pokemon/effects/field/field.cc" \
    "pokemon/effects/fixed/fixed.cc" \
    "pokemon/effects/healing/healing.cc" \
    "pokemon/effects/locked/locked.cc" \
    "pokemon/effects/multistrike/multistrike.cc" \
    "pokemon/effects/recoil/recoil.cc" \
    "pokemon/effects/special/special.cc" \
    "pokemon/effects/statModifiers/statModifiers.cc" \
    "pokemon/effects/status/status.cc"

# Effects test
run_test "tests/effects.test.cc" \
    "pokemon/constants/enums.cc" \
    "pokemon/effects/effects.cc" \
    "pokemon/effects/bind/bind.cc" \
    "pokemon/effects/charge/charge.cc" \
    "pokemon/effects/drain/drain.cc" \
    "pokemon/effects/field/field.cc" \
    "pokemon/effects/fixed/fixed.cc" \
    "pokemon/effects/healing/healing.cc" \
    "pokemon/effects/locked/locked.cc" \
    "pokemon/effects/multistrike/multistrike.cc" \
    "pokemon/effects/recoil/recoil.cc" \
    "pokemon/effects/special/special.cc" \
    "pokemon/effects/statModifiers/statModifiers.cc" \
    "pokemon/effects/status/status.cc"

# =============================================================================

echo "=============================="
echo " Test Summary"
echo "=============================="
echo "Total : $TOTAL"
echo "Passed: $PASSED"
echo "Failed: $FAILED"

if [[ $FAILED -ne 0 ]]; then
    exit 1
fi
