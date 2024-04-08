// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int getPriority(char sym) {
  if (sym == '(') {
    return 0;
  } else if (sym == ')') {
    return 1;
  } else if (sym == '+' || sym == '-') {
    return 2;
  } else if (sym == '*' || sym == '/') {
    return 3;
  } else {
    return -1;
  }
}

int operation(int a, int b, char sym) {
  switch (sym) {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '*':
      return a * b;
    case '/':
      return a / b;
  }
  return 0;
}

std::string infx2pstfx(std::string inf) {
  TStack<char, 100> stack;
  std::string post;
  int priority = 0;
  for (int i = 0; inf[i]; i++) {
    if (inf[i] >= '0' && inf[i] <= '9') {
      post += inf[i];
      if (i != inf.length() - 1) {
        post += " ";
      }
    } else if (inf[i] == '(') {
      stack.push(inf[i]);
    } else if (stack.isEmpty()) {
      stack.push(inf[i]);
    } else if (inf[i] == ')') {
      while (stack.stTop() != '(') {
        post += stack.pop();
        post += ' ';
      }
      stack.pop();
    } else if (getPriority(inf[i]) <= stack.stTop()) {
      while (getPriority(inf[i]) <= stack.stTop()) {
        post += stack.pop();
      }
      post += ' ';
      stack.push(inf[i]);
    }
  }
  while (!stack.isEmpty()) {
    post += stack.pop();
    post += ' ';
  }
  return post;
}

int eval(std::string pref) {
  int num1 = 0, num2 = 0;
  TStack<char,100> stack;
  std::string line;
  for (int i = 0; pref[i]; i++) {
    if (pref[i] >= '0' && pref[i] <= '9') {
        line += pref[i];
    } else if (pref[i] == ' ') {
      stack.push(std::stoi(line));
      line = "";
    } else {
      num1 = stack.pop();
      num2 = stack.pop();
      stack.push(operation(num1, num2, pref[i]));
    }
  }
  return stack.pop();
}
