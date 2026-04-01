# Developer Log (DEVLOG.md)
## Expression Format Detector + Stack Evaluator (Spring 2026)


## Allowed Entry Types
Each entry may be one of the following:

1) **Bug Fix Entry**
- The issue encountered.
- Error messages or symptoms.
- Attempts made.
- Final resolution.

2) **Edge Case / Testing Entry**
- A failure discovered through testing.
- The specific input/state that caused it.
- The change you made to handle it correctly.

3) **Engineering Decision Entry (up to 2 allowed)**
- A design decision you made.
- An alternative approach you considered.
- Why you chose one approach over another (tradeoffs).

---

### Entry 1
**Date:** 2026-03-30  
**Entry Type:**  Edge Case  
**Task worked on: isValidPostfix/isValidInfix()**  
**Issue or decision: was not chekcing to see if tokens was empty before checking the rest of tokens**  
**Error message / symptom (if applicable):**  
**What I tried: added a check with tokens.size()**  
**Fix / resolution (or final decision): added a quick check at the start of both functions that returns false if tokens is empty**  
**Commit(s): **

---

### Entry 2
**Date:** 2026-03-30  
**Entry Type:**  Engineering Decision  
**Task worked on: precedence()**  
**Issue or decision: was using an else if statement, was returning wrong values based on type of operator**  
**Error message / symptom (if applicable):**  
**What I tried: had a else-if statement to dictate the output of precedence(), had wrong logic for return values**  
**Fix / resolution (or final decision): decided to just make precedence() with two seperate if statemnts, corrected return values of for "*" and "/" to be greater than "+" and "-"**  
**Commit(s): **

---

### Entry 3
**Date:** 2026-03-31  
**Entry Type: Engineering Decision**    
**Task worked on: infixToPostfix()**  
**Issue or decision: numbers were being placed in temp not the output**  
**Error message / symptom (if applicable):**  
**What I tried: was using a vector to hold temp, but was not ideal for pull specific items**  
**Fix / resolution (or final decision): changed temp from vector to arraystack and corrected where numbers are held**  
**Commit(s): **

---

### Entry 4
**Date:** 2026-03-31  
**Entry Type: Edge Case**    
**Task worked on: evalPostfix() **  
**Issue or decision: when dividing was not checking if dividen was 0**  
**Error message / symptom (if applicable): would divide then check if dividen was 0**  
**What I tried: x/y then if y == 0 return 0.0**  
**Fix / resolution (or final decision): put check before division**  
**Commit(s): **

---

### Entry 5
**Date:** 2026-03-31  
**Entry Type: Bug Fix**    
**Task worked on: isValidInfix()**  
**Issue or decision: logic was not correct and was returning false for everything**  
**Error message / symptom (if applicable): only returned false**  
**What I tried: changed if condition to check for operators at each even and odd index**  
**Fix / resolution (or final decision): updated if condition for better filtering**  
**Commit(s): **

---

### Entry 6
**Date:** 2026-03-31  
**Entry Type: Bug Fix**    
**Task worked on: makeDouble()**  
**Issue or decision: I was trying to use tokens[i].value but was considered a string**  
**Error message / symptom (if applicable): **  
**What I tried: created makeDouble for conversion**  
**Fix / resolution (or final decision): makeDouble works in converting**  
**Commit(s): **

---

### Entry 7
**Date:** 2026-03-31  
**Entry Type: Edge Case**    
**Task worked on: infixToPostfix()**  
**Issue or decision: was not checking for any lost operators**  
**Error message / symptom (if applicable): **  
**What I tried: was not looking for any operators that may have been left**  
**Fix / resolution (or final decision):  added a while loop to check for lost operators**  
**Commit(s): **

---

### Entry 7
**Date:** 2026-03-31  
**Entry Type: Bug Fix**    
**Task worked on: ArrayStack.h**  
**Issue or decision: pop/top were not completed**  
**Error message / symptom (if applicable): pop did not use pop_back/ top was not returning top**  
**What I tried: set up frame for pop/top but was not completed**  
**Fix / resolution (or final decision):  added pop_back to pop/ and changed return for top to data[data.size() - 1**  
**Commit(s): **

---

### Entry 8
**Date:** 2026-03-31  
**Entry Type: Edge Case**    
**Task worked on: tokenize()**  
**Issue or decision: added final check !item.empty/ was not adding to tokens**  
**Error message / symptom (if applicable): tokenize was not taking those in items and adding to tokens**  
**What I tried: **  
**Fix / resolution (or final decision):  added else statment to bring those in items to tokens and return correct amount**  
**Commit(s): **

---