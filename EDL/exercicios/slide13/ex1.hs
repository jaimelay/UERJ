data Cmd = Atr String Exp   -- atribuicao, ex.: x=1
         | Seq Cmd Cmd      -- sequencia,  ex.: x=1 ; y=x
    deriving Show

data Exp = Num Int
         | Add Exp Exp
         | Sub Exp Exp
         | Var String
    deriving Show

type Mem = [(String,Int)]

-- 1.1
-- x = 1
-- R: c0 = Atr "x" (Num 1)
-- x = 1 + x - 20
-- R: c1 = Atr "x" (Sub (Add (Num 1) (Var "x")) (Num 20))
-- x = 1 ; y = 2 ; z = x+y
-- R: c2 = Seq (Seq (Atr "x" (Num 1)) (Atr "y" (Num 2))) (Atr "z" (Add (Var "x") (Var "y")))

-- 1.2
-- c0 = Atr "x" (Add (Num 1) (Num 2))
-- R: x = 1 + 2 -- (valor final x=3)
-- c1 = Seq (Atr "x" (Num 10)) (Atr "x" (Num 1))
-- R: x = 10; x = 1;
-- c2 = Seq (Atr "x" (Num 1)) (Seq (Atr "y" (Add (Var "x") (Num 1))) (Atr "x" (Var "y")))
-- R: x = 1; y = x + 1; x = y; 

-- 1.3

consulta :: Mem -> String -> Int
consulta [] id = 0
consulta ((id', v):xs) id = if (id == id') then v else consulta xs id

escreve :: Mem -> String -> Int -> Mem
escreve mem s v = (s, v):mem

avaliaExp :: Mem -> Exp -> Int
avaliaExp mem (Num v) = v;
avaliaExp mem (Add e1 e2) = (avaliaExp mem e1) + (avaliaExp mem e2) 
avaliaExp mem (Sub e1 e2) = (avaliaExp mem e1) - (avaliaExp mem e2)
avaliaExp mem (Var s) = consulta mem s

avaliaCmd :: Mem -> Cmd -> Mem
avaliaCmd mem (Atr str e) = escreve mem str (avaliaExp mem e)
avaliaCmd mem (Seq c1 c2) = avaliaCmd mem' c2 where mem' = avaliaCmd mem c1

main = print(avaliaExp [] e0)