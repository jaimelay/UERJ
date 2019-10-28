data Exp = Num Int |
            Add Exp Exp |
            Sub Exp Exp
    deriving Show

--  1.1
-- 1
e0 = Num 1
-- 1 + 10 - 20
e1 = Sub (Add (Num 1) (Num 10)) (Num 20)
-- 1 + (10 - 20)
e2 = Add (Num 1) (Sub (Num 10) (Num 20))
-- (5 + 5) - (5 - 5)
e3 = Sub (Add (Num 5) (Num 5)) (Sub (Num 5) (Num 5))

-- 1.2
-- e0 = Add (Num 1) (Num 2)
-- R: 1 + 2
-- e1 = Add (Add (Add (Num 1) (Num 2)) (Num 3)) (Num 4)
-- R: ((1 + 2) + 3) + 4
-- e2 = Add (Num 1) (Add (Num 2) (Add (Num 3) (Num 4)))
-- R: 1 + (2 + (3 + 4))
-- e3 = Sub (Sub (Sub (Num 1) (Num 2)) (Num 3)) (Num 4)
-- R: ((1 - 2) - 3) - 4
-- e4 = Sub (Num 1) (Sub (Num 2) (Sub (Num 3) (Num 4)))
-- R: 1 - (2 - (3 - 4))
-- e5 = Sub (Sub (Num 1) (Num 2)) (Sub (Num 3) (Num 4))
-- R: (1 - 2) - (3 - 4)

-- 1.3
avalia :: Exp -> Int
avalia (Num x) = x
avalia (Add e1 e2) = avalia e1 + avalia e2
avalia (Sub e1 e2) = avalia e1 - avalia e2

-- 1.4
avalia' :: Exp -> Exp
avalia' (Num x) = (Num x)
avalia' (Add e1 e2) = (Num (f (avalia' e1) (avalia' e2)))
    where f (Num x) (Num y) = x + y
avalia' (Sub e1 e2) = (Num (g (avalia' e1) (avalia' e2)))
    where g (Num x) (Num y) = x - y

-- main = print(e0, e1, e2, e3)
-- main = print(avalia e0, avalia e1, avalia e2, avalia e3)
main = print(avalia' e0, avalia' e1, avalia' e2, avalia' e3)