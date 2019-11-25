import Debug.Trace

data Cmd = Atr String Exp   -- atribuicao, ex.: x=1
         | Seq Cmd Cmd      -- sequencia,  ex.: x=1 ; y=x
         | Dcl String       -- declaracao, ex.: int x
    deriving Show

data Exp = Num Int
         | Add Exp Exp
         | Sub Exp Exp
         | Var String
    deriving Show


type Mem = [(String, Int)]

escreve :: Mem -> String -> Int -> Mem
escreve mem s v = (s, v):mem

consulta :: Mem -> String -> Int
consulta [] id = 0
consulta ((id', v):l) id = if (id' == id) then v else consulta l id
 
verificaExp :: [String] -> Exp -> Bool
verificaExp lista (Var s) = elem s lista
verificaExp lista (Add e1 e2) = (verificaExp lista e1) && (verificaExp lista e2)
verificaExp lista (Sub e1 e2) = (verificaExp lista e1) && (verificaExp lista e2)
verificaExp _ _ = True

avaliaExp :: Mem -> Exp -> Int
avaliaExp mem (Num x) = x
avaliaExp mem (Add e1 e2) = (avaliaExp mem e1) + (avaliaExp mem e2)
avaliaExp mem (Sub e1 e2) = (avaliaExp mem e1) - (avaliaExp mem e2)
avaliaExp mem (Var s) = consulta mem s

verificaCmd :: [String] -> Cmd -> ([String], Bool)
verificaCmd lista (Dcl s) = (s:lista, True)
verificaCmd lista (Atr s e) = (lista, (elem s lista) && (verificaExp lista e))
verificaCmd lista (Seq c1 c2) = (l2, b1 && b2)
                                            where 
                                                (l1, b1) = verificaCmd lista c1
                                                (l2, b2) = verificaCmd l1 c2

avaliaCmd :: Mem -> Cmd -> Mem
avaliaCmd mem (Dcl _) = mem
avaliaCmd mem (Atr s e) = escreve mem s (avaliaExp mem e)
avaliaCmd mem (Seq c1 c2) = avaliaCmd mem' c2 where mem' = avaliaCmd mem c1

verificaProg :: Cmd -> Bool
verificaProg cmd = b where (lista, b) = verificaCmd [] cmd

avaliaProg :: Cmd -> Maybe Int
avaliaProg cmd = if (verificaProg cmd) then Just (avaliaExp (avaliaCmd [] cmd) (Var "ret")) else Nothing

main = print()