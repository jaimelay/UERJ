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

verificaExp :: [String] -> Exp -> Bool
verificaExp lista (Var str) = elem str lista
verificaExp lista (Add e1 e2) = (verificaExp lista e1) && (verificaExp lista e2)
verificaExp lista (Sub e1 e2) = (verificaExp lista e1) && (verificaExp lista e2)
verificaExp _ _ = True

verificaCmd :: [String] -> Cmd -> ([String], Bool)
verificaCmd lista (Dcl s) = (s:lista, True)
verificaCmd lista (Atr s e) = (lista, (elem s lista) && (verificaExp lista e))
verificaCmd lista (Seq c1 c2) = (s2, b1 && b2)
                                        where
                                            (s1, b1) = verificaCmd lista c1
                                            (s2, b2) = verificaCmd s1 c2

main = print()