#include <stdio.h>
#include <stdlib.h>

/*
    There are three main ways of writing expressions.
        1. Infix: <operand> <operator> <operand>
            eg: a + b
        2. Prefix: <operator> <operand> <operand>
            eg: +ab
        3. Postfix: <operand> <operand> <operator>
            eg: ab+

    Why do we need Postfix or Prefix
    Becasue the infix way of writing expressions require us to follow the BODMAS approach, it means 
    we have to scan the expression multiple times to find the next operator of highest precedence.
    This multiple scans is undesirable since it's time consuming. 

        eg: 8 + 3 * (9-6)/ 2^2 + 6/2        -> this the infix way

    So we want a way to evaluate the expression with just a single scan which will save us a lot of time.
    Fortunately, the postfix approach can help us do this.

        for the same expression above we can re-write it in the postfix form as:
            8 3 9 6 - 2^2 / * + 6 2 / +
                how this works is that, we skip any operand and only perform an action 
                when we encouter an operator. The operator acts on the previous 2 operands

                symbol          precedence      associativity
                +, -                1               L-R
                *, /                2               L-R
                ^ (power)           3               R-L
                -, log, !(unary)    4               R-L
                ()                  5               L-R

    Converting from Infix to Postfix
        * make sure all expressions are fully parenthesized.
        * parenthesization is done according to the precedence of the operators, 
        * if two operators have the same precedence, consider according to their associativity
        * then convert to postfix by performing the operations in order
        
        eg: given a+b*c
            - we first parenthesize (b*c) since * has a higher precedence than +
            - then we parenthesize (a+(b*c))
            - therefore (a+(b*c)) => (a +[bc*]) => a b c * +
        
            given a+b+c*d
            - ((a+b)+(c*d)) => ((a+b)+[cd*]) => ([ab+]+[cd*]) => ab + cd* +

        This whole conversion process can be implemented using a stack
            * we iterate over the exp until a null character is reached.
            * if an operand is encountered, we append it to the postfix expression
            * else if we encounter an operator, 
                 - if the stack is empty, we push the operator onto stack
                 - else if the precedence of the encountered operator is greater than the precedence of the operator of stackTop, 
                    we push the encountered operator on stackTop
                 - else pop the stackTop operator from stack

*/