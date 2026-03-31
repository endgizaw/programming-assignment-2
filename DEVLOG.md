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