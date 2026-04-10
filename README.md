# NeetCode 150

This repository is for tracking and storing NeetCode 150 solutions in C++.

## Structure

- `cpp/` contains C++ solutions grouped by topic.
- `progress.md` tracks completed problems and where each solution lives.

## Folder Layout

The repo uses these topic folders:

- `arrays-and-hashing`
- `two-pointers`
- `stack`
- `binary-search`
- `sliding-window`
- `linked-list`
- `trees`
- `heap-priority-queue`
- `backtracking`
- `tries`
- `graphs`
- `advanced-graphs`
- `1-d-dp`
- `2-d-dp`
- `greedy`
- `intervals`
- `math-and-geometry`
- `bit-manipulation`

## Naming Convention

Use one file per problem:

- C++: `problem-name.cpp`

Example:

- `cpp/arrays-and-hashing/two-sum.cpp`

## Suggested Workflow

1. Solve the problem on LeetCode.
2. Paste the accepted C++ solution into the matching topic folder here.
3. Update `progress.md` so the repo stays easy to browse.

## Local Testing Workflow

This repo uses a shared `input.txt` and `output.txt` at the project root for local runs in VS Code.

- Put reusable problem-specific test cases next to the solution file.
- Use the naming pattern `problem-name-tests.txt`.
- Copy the test cases you want to try into `input.txt`.
- Run the current C++ file from VS Code.
- Check `output.txt` for the result.

Example:

- `cpp/stack/valid-parentheses.cpp`
- `cpp/stack/valid-parentheses-tests.txt`
- `input.txt`
- `output.txt`

## Notes

- Keep the file name close to the LeetCode problem title.
- If a problem has multiple approaches, add suffixes like `-bruteforce`, `-optimal`, or `V2`.
- If LeetCode requires a class named `Solution`, that is fine. The file name can still be descriptive.
