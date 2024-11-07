import re

# Define the token types and their regex patterns
token_specification = [
    ('input', r'input'),            # input keyword
    ('print', r'print'),            # print keyword
    ('id', r'[a-zA-Z_][a-zA-Z0-9_]*'),  # identifiers
    ('number', r'\d+(\.\d+)?'),     # integers and floats
    ('lparen', r'\('),              # left parenthesis
    ('rparen', r'\)'),              # right parenthesis
    ('add_op', r'[+-]'),            # addition and subtraction
    ('mult_op', r'[*/%]'),          # multiplication and modulus
    ('assign_op', r'='),            # assignment operator
    ('comment', r'/\*.*?\*/'),      # comments
    ('new_line', r'\n'),            # newline
    ('whitespace', r'\s+'),         # whitespace
    ('error', r'.'),                # catch all for errors
]

# Compile the regex patterns
token_regex = '|'.join(f'(?P<{pair[0]}>{pair[1]})' for pair in token_specification)
get_token = re.compile(token_regex)

def lexer(code):
    tokens = []
    for match in get_token.finditer(code):
        kind = match.lastgroup
        value = match.group()
        if kind == 'whitespace' or kind == 'new_line':
            continue  # Skip whitespace and new lines
        elif kind == 'comment':
            tokens.append(('<comment>', value.strip()))
        elif kind == 'error':
            tokens.append(('<error>', f'Invalid token: {value}'))
        else:
            tokens.append((f'<{kind}>', value))
    return tokens

# Sample program as input
input_program = """
input(a)  
input(b) 
input(c) 
total = a + b + c  /* get a sum of three inputs */ 
average = total / 3  /* compute an average */ 
print(total) 
print(average) 
"""

# Tokenize the input program
tokens = lexer(input_program)

# Display the tokens
for token in tokens:
    print(token)
