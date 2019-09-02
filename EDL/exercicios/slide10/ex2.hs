turma1 :: [(String, Float, Float)]
turma1 = [ ("Joao",7.5,3.5), ("Maria",10.0,8.0), ("Jose",5.0,3.0) ]

nome :: (String, Float, Float) -> String
nome (nm,_,_) = nm

nota1 :: (String, Float, Float) -> Float
nota1 (_,n1,_) = n1

nota2 :: (String, Float, Float) -> Float
nota2 (_,_,n2) = n2

media :: (String, Float, Float) -> Float
media aluno = ((nota1 aluno) + (nota2 aluno)) / 2

medias :: [ (String, Float, Float) ] -> [Float]
medias turma = map media turma

-- 2.1
notas1 :: [Float]
notas1 = map nota1 turma1

notas2 :: [Float]
notas2 = map nota2 turma1

medias2 :: [Float]
medias2 = map media turma1

-- 2.2
acima_de_oito :: (String, Float, Float) -> Bool
acima_de_oito (_,x,y) = (x >= 8.0 && y >= 8.0)

turma_acima_de_oito :: [(String, Float, Float)]
turma_acima_de_oito = filter acima_de_oito turma1

oitos :: [(String, Float, Float)] -> [String]
oitos turma = map nome turma

-- 2.3
sum_of_all_p1 :: Float
sum_of_all_p1 = foldr (+) 0 notas1

sum_of_all_p2 :: Float
sum_of_all_p2 = foldr (+) 0 notas2

sum_of_all_medias :: Float
sum_of_all_medias = foldr (+) 0 medias2

converte :: Int -> Float
converte x = fromIntegral x :: Float

tamanho_turma :: Float
tamanho_turma = converte (length turma1)

todas :: [(String, Float, Float)] -> (Float, Float, Float)
todas turma = ((sum_of_all_p1/tamanho_turma), (sum_of_all_p2/tamanho_turma), (sum_of_all_medias/tamanho_turma))

-- 2.4
abaixo_de_cinco :: Float -> Bool
abaixo_de_cinco x = (x <= 5.0)

notas1_abaixo :: [Float]
notas1_abaixo = filter abaixo_de_cinco notas1

notas2_abaixo :: [Float]
notas2_abaixo = filter abaixo_de_cinco notas2

baixas :: [Float]
baixas = (notas1_abaixo ++ notas2_abaixo)

-- 2.5
aprovacao :: Float -> String
aprovacao x = if x >= 7.0 then "(Aprovado)" else "(Reprovado)"

media2 :: Float -> Float -> Float
media2 x y = (x + y) / 2

filtraTudo :: (String, Float, Float) -> String
filtraTudo (a,b,c) = a ++ " " ++ show (media2 b c) ++ " " ++ aprovacao (media2 b c) ++ "\n"

pretty2 :: [String] -> String
pretty2 (x:xs) = x ++ concat xs

pretty :: [(String, Float, Float)] -> [String]
pretty turma = map filtraTudo turma

-- main = print(notas1, oitos turma_acima_de_oito, todas turma1, baixas)
main = putStr (pretty2 (pretty turma1))