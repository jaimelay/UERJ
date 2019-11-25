data Cmd = Atr String Exp | Seq [Cmd]
    deriving Show

data Exp = Num Int | Add Exp Exp | Sub Exp Exp | Var String
    deriving Show

type Mem = [(String, Int)]

escreve :: Mem -> String -> Int -> Mem
escreve m s v = (s, v):m

consulta :: Mem -> String -> Int
consulta [] id = 0
consulta ((id', v):l) id = if (id' == id) then v else consulta l id

avaliaExp :: Mem -> Exp -> Int
avaliaExp m (Num v) = v
avaliaExp m (Add e1 e2) = avaliaExp m e1 + avaliaExp m e2
avaliaExp m (Sub e1 e2) = avaliaExp m e1 - avaliaExp m e2
avaliaExp m (Var s) = consulta m s

avaliaCmd :: Mem -> Cmd -> Mem
avaliaCmd m (Atr s e) = escreve m s (avaliaExp m e)
avaliaCmd m (Seq []) = m
avaliaCmd m (Seq (x:xs)) = avaliaCmd m (Seq xs) where m' = avaliaCmd m x

main = print()