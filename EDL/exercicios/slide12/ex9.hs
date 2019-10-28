data Cmd = Atr String Exp | Seq [Cmd]
    deriving Show

data Exp = Num Int | Add Exp Exp | Sub Exp Exp | Var String
    deriving Show

type Mem = [(String, Int)]

memoria :: Mem
memoria = []

consulta :: Mem -> String -> Int
consulta ((id', v):l) id = if id' == id then v else consulta l id 

escreve :: Mem -> String -> Int -> Mem
escreve mem id v = (id, v):mem

avaliaExp :: Mem -> Exp -> Int
avaliaExp mem (Num x) = x
avaliaExp mem (Add e1 e2) = avaliaExp mem e1 + avaliaExp mem e2
avaliaExp mem (Sub e1 e2) = avaliaExp mem e1 - avaliaExp mem e2
avaliaExp mem (Var s) = consulta mem s

avaliaCmd :: Mem -> Cmd -> Mem
avaliaCmd mem (Atr id exp) = escreve mem id (avaliaExp mem exp)
avaliaCmd mem (Seq (x:xs)) = avaliaCmd (avaliaCmd mem x) (Seq xs)
avaliaCmd mem (Seq []) = mem

c0 = Atr "x" (Num 1)
c1 = Atr "x" (Sub (Add (Num 1) (Var "x")) (Num 20))
c2 = Atr "x" (Add (Add (Num 5) (Var "x")) (Num 20))

c4 = Seq [c0, c1, c2]

main = print(avaliaCmd memoria c4)