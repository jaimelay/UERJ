data Exp = Num Int |
            Add Exp Exp |
            Sub Exp Exp |
            Mult Exp Exp |
            Div Exp Exp
    deriving Show

e0 = Mult (Add (Num 10) (Num 20)) (Num 10)
e1 = Div (e0) (Num 10)

avalia :: Exp -> Int
avalia (Num x) = x
avalia (Add e1 e2) = avalia e1 + avalia e2
avalia (Sub e1 e2) = avalia e1 - avalia e2
avalia (Mult e1 e2) = avalia e1 * avalia e2
avalia (Div e1 e2) = div (avalia e1) (avalia e2)

avalia' :: Exp -> Exp
avalia' (Num x) = (Num x)
avalia' (Add e1 e2) = (Num (f (avalia' e1) (avalia' e2)))
    where f (Num x) (Num y) = x + y
avalia' (Sub e1 e2) = (Num (f (avalia' e1) (avalia' e2)))
    where f (Num x) (Num y) = x - y
avalia' (Mult e1 e2) = (Num (f (avalia' e1) (avalia' e2)))
    where f (Num x) (Num y) = x * y
avalia' (Div e1 e2) = (Num (f (avalia' e1) (avalia' e2)))
    where f (Num x) (Num y) = div x y

-- main = print(avalia e0, avalia e1)
main = print(avalia' e0, avalia' e1)