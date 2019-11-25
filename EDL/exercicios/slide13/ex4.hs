data Cmd = Atr String Exp
         | Seq Cmd Cmd
         | Cnd Exp Cmd Cmd
         | Rep Exp Cmd
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
avaliaExp m (Num x) = x
avaliaExp m (Add e1 e2) = (avaliaExp m e1) + (avaliaExp m e2)
avaliaExp m (Sub e1 e2) = (avaliaExp m e1) - (avaliaExp m e2)
avaliaExp m (Var s) = consulta m s

avaliaCmd :: Mem -> Cmd -> Mem
avaliaCmd m (Atr s e) = escreve m s (avaliaExp m e)
avaliaCmd m (Seq c1 c2) = avaliaCmd m' c2 where m' = avaliaCmd m c1
avaliaCmd m (Cnd e c1 c2) = if (avaliaExp m e) /= 0 then avaliaCmd m c1 else avaliaCmd m c2
avaliaCmd m (Rep e c1) = if (avaliaExp m e) /= 0 then m else avaliaCmd (avaliaCmd m c1) (Rep e c1)

main = print()