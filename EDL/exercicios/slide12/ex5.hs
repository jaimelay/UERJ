data Exp = Num Int |
            Add Exp Exp |
            Sub Exp Exp |
            Mult Exp Exp |
            Div Exp Exp |
            And Exp Exp |
            Or Exp Exp |
            Not Exp
    deriving Show

e0 = And (Num 1) (Num 0)
e1 = Or (Num 0) (Num 0)
e2 = Not (Num 1)

avalia :: Exp -> Int
avalia (Num x) = x
avalia (Add e1 e2) = avalia e1 + avalia e2
avalia (Sub e1 e2) = avalia e1 - avalia e2
avalia (Mult e1 e2) = avalia e1 * avalia e2
avalia (Div e1 e2) = div (avalia e1) (avalia e2)
avalia (And e1 e2) = if ((avalia e1) * (avalia e2) /= 0) then 1 else 0
avalia (Or e1 e2) = if ((avalia e1) + (avalia e2) == 0) then 0 else 1
avalia (Not e1) = if (avalia e1 == 0) then 1 else 0

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
avalia' (And e1 e2) = (Num (f (avalia' e1) (avalia' e2)))
    where f (Num x) (Num y) = if (x * y /= 0) then 1 else 0
avalia' (Or e1 e2) = (Num (f (avalia' e1) (avalia' e2)))
    where f (Num x) (Num y) = if (x + y == 0) then 0 else 1
avalia' (Not e1) = (Num (f (avalia' e1)))
    where f (Num x) = if x == 0 then 1 else 0

-- main = print(avalia e0, avalia e1, avalia e2)
main = print(avalia' e0, avalia' e1, avalia' e2)