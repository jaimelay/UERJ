data Cmd = Atr String Exp   -- atribuicao, ex.: x=1
         | Seq Cmd Cmd      -- sequencia,  ex.: x=1 ; y=x
    deriving Show

data Exp = Num Int
         | Add Exp Exp
         | Sub Exp Exp
         | Var String
    deriving Show

type Mem = [(String, Int)]

memoria :: Mem
memoria = []

consulta :: Mem -> String -> Int
consulta [] id = 0
consulta ((id', x):l) id = if (id' == id) then x else consulta l id

escreve :: Mem -> String -> Int -> Mem
escreve mem id v = (id, v):mem

avaliaExp :: Mem -> Exp -> Int
avaliaExp mem (Num x) = x
avaliaExp mem (Add e1 e2) = avaliaExp mem e1 + avaliaExp mem e2
avaliaExp mem (Sub e1 e2) = avaliaExp mem e1 - avaliaExp mem e2
avaliaExp mem (Var s) = consulta mem s

avaliaCmd :: Mem -> Cmd -> Mem
avaliaCmd mem (Atr s exp) = escreve mem s (avaliaExp mem exp)
avaliaCmd mem (Seq c1 c2) = avaliaCmd (avaliaCmd mem c1) c2

avaliaProg :: Cmd -> Int
avaliaProg cmd = avaliaExp (avaliaCmd [] cmd) (Var "ret")

c0 = Seq (Atr "x" (Num 1)) (Seq (Atr "y" (Num 2)) (Atr "ret" (Add (Var "x") (Var "y"))))

main = print(avaliaProg c0)