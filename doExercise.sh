# ===================================================================================================
# Script to create files to solve a problem from a specified Judge in a particular language.
# ===================================================================================================
#!/bin/bash

# Templates with code snippets folder
TEMP_FOLDER="./Templates"

if [ $# -ne 3 ]; then
  echo "======================================================================================"
  echo "Usage:> $0 <name> <judge> <language>"
  echo "--------------------------------------------------------------------------------------"
  echo "<judge>"
  echo "1) Kattis"
  echo "2) UVA-Online-Judge"
  echo "--------------------------------------------------------------------------------------"
  echo "<language>"
  echo "1) C++"
  echo "2) Java"
  echo "3) Python"
  echo "======================================================================================"
  exit
else
  PROBLEM_NAME=$1
  JUDGE_NAME=$2
  LANGUAGE_NAME=$3
  echo "./$JUDGE_NAME/$PROBLEM_NAME"
  if [ $LANGUAGE_NAME == "C++" ]; then
    mkdir -p "./$JUDGE_NAME/$PROBLEM_NAME"
    cp "$TEMP_FOLDER/main.cpp" "./$JUDGE_NAME/$PROBLEM_NAME"
    cp "$TEMP_FOLDER/Makefile" "./$JUDGE_NAME/$PROBLEM_NAME"
    cp "$TEMP_FOLDER/in" "./$JUDGE_NAME/$PROBLEM_NAME"
    echo "./$JUDGE_NAME/$PROBLEM_NAME"
  elif [ $LANGUAGE_NAME == "Java" ]; then
    mkdir -p "./$JUDGE_NAME/$LANGUAGE_NAME/$PROBLEM_NAME"
    cp "$TEMP_FOLDER/main.java" "./$JUDGE_NAME/$LANGUAGE_NAME/$PROBLEM_NAME"
    cp "$TEMP_FOLDER/in" "./$JUDGE_NAME/$LANGUAGE_NAME/$PROBLEM_NAME"
    echo "./$JUDGE_NAME/$LANGUAGE_NAME/$PROBLEM_NAME"
  elif [ $LANGUAGE_NAME == "Python" ]; then
    mkdir -p "./$JUDGE_NAME/$LANGUAGE_NAME/$PROBLEM_NAME"
    cp "$TEMP_FOLDER/main.py" "./$JUDGE_NAME/$LANGUAGE_NAME/$PROBLEM_NAME"
    cp "$TEMP_FOLDER/in" "./$JUDGE_NAME/$LANGUAGE_NAME/$PROBLEM_NAME"
    echo "./$JUDGE_NAME/$LANGUAGE_NAME/$PROBLEM_NAME"
  fi
fi
