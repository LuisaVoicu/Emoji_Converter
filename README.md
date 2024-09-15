# Emoji Converter

## Overview

"Emoji Converter" is a program designed to allow users to input English text and convert key words into emojis. The goal of the project is to provide an interactive and universal method of communication.

## Project Requirements

The project requirements include:

1. **Word to Emoji Translation**: The program translates words into the most appropriate emojis. For example, the word "dog" is translated into "🐶".
2. **Expression and Phrase Interpretation**: Besides individual words, the program can interpret and translate expressions and phrases. For example, "Birds sing happily" becomes "🐦 🎤 😊". The phrase "Happy birthday" is recognized as a single expression and translated to "🥳".
3. **Cardinality Handling**: The program can represent a number of objects by repeating the corresponding emoji, e.g., "3 birds" is converted to "🐦🐦🐦".
4. **Synonym Handling**: The program includes a list of synonyms used when a user inputs a word that is not part of the core vocabulary. For instance, "kitten" is a synonym for "cat" and both are translated into "🐱".
5. **Handling Unrecognized Expressions**: When an unknown word is input, the program attempts to match it with integrated lexical fields and represents it using emojis to suggest the described word. Examples include:
    - "thing" -> "(🌳 💻 🚗)"
    - "meal" -> "(🍔 🍟 🍕)"
    - "profession" -> "(💼 🔨 💻)"
    - "human" -> "(👨 👩 🧒)"

## Technical Details

### Tokens
- **<subject_flag>**: Tokens for common nouns and pronouns, representing the subject of a sentence.
- **<adjective_flag>**: Tokens reserved for adjectives.
- **<verb_flag>**, **<adverb_flag>**: Tokens for verbs and adverbs.

### Grammar
The grammar defines the syntactic structure of the language, illustrating the composition of poetry:
- **Poem**: Represents the entire poem, consisting of lines.
- **Lines**: A line consists of one or more sentences followed by a newline.
- **Sentences**: A sentence can contain a subject, adjectives, verbs, and adverbs in various combinations.
- **Subjects**: Can be personal pronouns, simple nouns, or combinations of nouns and numeral adjectives.
- **Verbs**: Describe common actions (eat, drink, sing, etc.) and can detect past tense verbs.
- **Adverbs**: Used for properties associated with verbs (sadly, happily, etc.).

### Program Structure
- **Lexical Analyzer**: Tokenizes the text provided by the user, breaking it into characters to detect keywords and producing corresponding tokens for the Syntactic Analyzer.
- **Syntactic Analyzer**: Analyzes the syntactic structure of tokens received from Lex, creating a parse tree based on defined grammatical rules.

### Development Environment Setup
1. Install Flex and Bison:
    ```bash
    sudo apt-get update
    sudo apt-get install flex bison
    ```
2. Lex and Yacc Files: The project contains two files, `.l` and `.y`, which handle word input, token detection, processing according to grammar, executing necessary operations, and delivering the converted text to the user.
3. Input File: A `.txt` file contains various texts such as poems, words, or sentences to cover special cases and highlight program functionalities. Users can add other files with their text and specify the file at runtime.

### Running the Program
1. Compile the program:
    ```bash
    lex emoji.l
    yacc emoji.y
    gcc y.tab.c -ll -ly
    ```
2. Run the program:
    ```bash
    ./a.out < input.txt
    ```

## Implementation Details

### Lex Functions
- **Synonym Identification**: The `get_main_token` function finds synonyms and replaces unknown words (`UNKNOWN_WORD`) with the main corresponding token.
- **Lowercase Conversion**: The `to_lower` function converts all words to lowercase to ensure uniform input processing.

### Main Yacc Subroutines
- **`print_emoji` Function**: Adds each repetition of an emoji to the main buffer using the `save_buffer` function.
- **`process_expression` Function**: Displays an expression formed from a sequence of words.
- **`save_buffer` Function**: Saves words or emojis in the main buffer, adding a space after each word to separate elements.
- **`replace_expressions_in_buffer` Function**: Replaces certain combinations of emojis and words in the buffer with predefined expressions.
- **`replace_unknown_word_with_emojis` Function**: Replaces unknown words with a sequence of emojis.

## Testing and Validation

### Test Cases and Results
Example test sentences and their emoji conversions:

- `the bird flies quickly` -> `the 🐦 ✈️ 🏃`
- `a big dog runs happily` -> `a 💪 🐶 🏃 😊`
- `she dances gracefully` -> `👧 💃 🩰`
- `3 birds sing loudly` -> `🐦🐦🐦 🎤 🔊`

### Special Cases
- Recognizing expressions
- Displaying a number of nouns
- Replacing unknown words with synonyms
- Representing unknown words using known lexical fields
- Handling verbs in the past tense and plural nouns

## Evaluation

### Strengths
- Interpretation of various forms of a word (plural, singular; past, present tense).
- Recognition of word combinations as expressions and representation by a single emoji.
- Unknown words go through two stages of potential matching with known tokens.

### Weaknesses
- Some words are associated with the same emoji.
- Connecting words like "the", "at", "with" do not have a corresponding emoji and are passed unchanged.
- The structure of verses is limited, leading to unrecognized input in some cases.
- Punctuation marks are ignored.

### Future Developments
- Expanding the dictionary of unknown words and finding more efficient ways to represent words without a corresponding emoji.
- Integrating more languages, allowing the program to translate texts from multiple languages.
- Integrating the program into a lyrics application where words are converted into emojis and displayed rhythmically.

## Conclusion
The Emoji Converter project offers an interactive and efficient solution for translating text into emojis, fulfilling the initial requirements and providing users with a universal method of communication. Further improvements could include expanding the dictionary, supporting multiple languages, and making the application more accessible to users.
