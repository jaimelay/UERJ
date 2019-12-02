-- exs
--  - pares
--  - multiplos args
--  - Exp.Arg
--  - Exp.Func
--  - data Mem a

import Debug.Trace

type Mem = [(String,Int)]

consulta :: [(String,a)] -> String -> a
consulta []           id = undefined
consulta ((id',v'):l) id = if id == id' then
                            v'
                           else
                            consulta l id

escreve :: [(String,a)] -> String -> a -> [(String,a)]
escreve l id v = (id,v):l

-------------------------------------------------------------------------------

data Exp = Num Int
         | Add Exp Exp
         | Sub Exp Exp
         | Var String
         | App String Exp
         | App2 String Exp Exp
  deriving Show

avaliaExp :: Env -> Exp -> Int
avaliaExp _         (Num v)     = v
avaliaExp env       (Add e1 e2) = (avaliaExp env e1) + (avaliaExp env e2)
avaliaExp env       (Sub e1 e2) = (avaliaExp env e1) - (avaliaExp env e2)
avaliaExp (mem,_)   (Var id)    = consulta mem id
avaliaExp (mem,cod) (App id e)  = ret where
                                    ret = consulta mem'' "ret"
                                    (mem'',_) = avaliaCmd (mem',cod) fun
                                    mem' = escreve mem "arg" arg
                                    arg  = avaliaExp (mem,cod) e
                                    fun  = consulta cod id
avaliaExp (mem,cod) (App2 id e1 e2)  = ret where
                                            ret = consulta mem'' "ret"
                                            (mem'',_) = avaliaCmd (mem',cod) fun
                                            mem' = escreve memTmp "arg2" arg2 where
                                                    memTmp = escreve mem "arg" arg
                                            arg  = avaliaExp (mem,cod) e1
                                            arg2 = avaliaExp (mem,cod) e2
                                            fun  = consulta cod id
-------------------------------------------------------------------------------

type Cod = [(String,Cmd)]
type Env = (Mem,Cod)

data Cmd = Atr String Exp
         | Prt Exp
         | Seq Cmd Cmd
         | Cnd Exp Cmd Cmd
         | Fun String String Cmd
         | Fun2 String String String Cmd
  deriving Show

avaliaCmd :: Env -> Cmd -> Env
avaliaCmd env       (Prt e)         = traceShow (avaliaExp env e) env
avaliaCmd (mem,cod) (Atr id exp)    = (escreve mem id v,cod) where
                                        v = avaliaExp (mem,cod) exp
avaliaCmd env       (Seq c1 c2)     = avaliaCmd env' c2 where
                                        env' = avaliaCmd env c1
avaliaCmd env       (Cnd exp c1 c2) = if (avaliaExp env exp) /= 0 then
                                        avaliaCmd env c1
                                      else
                                        avaliaCmd env c2
avaliaCmd (mem,cod) (Fun id x cmd)      = (mem, escreve cod id cmd') where
                                            cmd' = Seq (Atr "x" (Var "arg")) cmd
avaliaCmd (mem, cod) (Fun2 id x y cmd) = (mem, escreve cod id cmd') where
                                            cmd' = Seq (Seq (Atr "x" (Var "arg")) (Atr "y" (Var "arg2"))) cmd
-------------------------------------------------------------------------------

p3 = Seq (Fun2 "soma" "x" "y" (Atr "ret" (Add (Var "x") (Var "y")))) (Prt (App2 "soma" (Num 40) (Num 20)))

main = print (avaliaCmd ([],[]) p3)