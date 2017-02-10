
function ir_a_CAP(i){
	i.innerHTML = ' <div style="width:100%; float:left; text-align:center; color:#045FB4;">\
						<img style="width:70%; height:30%; float:left; padding:3% 15%;" src="./images/arbol_CAP.png" alt="Arbol CAP">\
					</div>\
					<div style="width:100%; float:center; text-align:left; color:#045FB4;">\
						<p style="padding:1% 5%;"><span style="font-weight:bold;">CA</span>: el sistema garantiza que todos los nodos estén disponibles y que los datos sean consistentes,\
							pero no garantiza que se traten las peticiones si un nodo se separa de la red.<br/>\
							<span style="font-weight:bold;">AP</span>: el sistema garantiza que todas las peticiones serán tratadas, aunque los nodos se separen de la red,\
							pero no garantiza que los datos sean consistentes.<br/>\
							<span style="font-weight:bold;">CP</span>: el sistema garantiza que los datos serán consistentes y que las peticiones serán tratadas,\
							aunque los nodos se separen de la red, pero no garantiza que el sistema responda siempre.<br/>\
						</p>\
					</div>\
					<div style="width:100%; float:center; text-align:left; color:#045FB4;">\
						<p style="padding:1% 5%;"><span style="font-weight:bold;">Documentales</span>: Almacenan la información de forma semiestructurada, es decir, en documentos cuyo formato puede ser JSON o BSON.\
							Estos documentos son similares a los registros de una BBDD relacional, con la diferencia de que no son tan rígidos; es decir,\
							un documento puede tener unos atributos distintos a los de otro documento, y ambos estar en la misma BBDD.\
							Los documentos están direccionados por una clave única mediante la cual se recupera la información,\
							pero estas BBDD también cuentan con un API que permite recuperar la información asociada a un campo o campos específicos.\
							La gran ventaja de estos sistemas es que puedes introducir un documento entero directamente sin tener que mapearlo primero a ningún modelo, como el entidad-relación,\
							siempre que lo pases a formato JSON primero.Son sistemas que bien pueden ser consistentes o eventualmente consistentes.<br/>\
							<span style="font-weight:bold;">Columnares</span>: Almacenan la información en forma de columnas. Cuentan con una clave primaria para obtener y actualizar los datos.\
							Son parecidas a las BBDD relacionales, pero utilizando columnas en lugar de registros. Están orientadas al tratamiento de grandes cantidades de datos.\
							Son sistemas eventualmente consistentes<br/>\
							<span style="font-weight:bold;">Clave-valor</span>: Almacenan la información mediante tuplas que contienen una clave y un valor. Al igual que las columnares,\
							también cuentan con una clave primaria para obtener y actualizar los datos. A la hora de obtener información, simplemente hay que buscar por la clave para recuperar el valor.\
							Son sistemas eventualmente consistentes.<br/>\
							<span style="font-weight:bold;">Grafo</span>: Almacenan la información en forma de grafos, utilizando los nodos (se muestran mediante círculos) y aristas (se muestran mediante flechas)\
							para representar los datos almacenados. Los nodos representan las entidades, y pueden tener cualquier número de atributos, cada uno como un par clave-valor,\
							así como una etiqueta indicando su rol en el dominio del grafo. Las aristas representan las relaciones entre los nodos, siempre tienen dirección, tipo, nodo inicial y nodo final,\
							y, al igual que éstos, pueden tener cualquier número de atributos. Aunque tengan dirección, las relaciones pueden ser recorridas en ambos sentidos.\
							Gracias a que estas relaciones se almacenan correctamente, dos nodos pueden compartir cualquier número o tipo de relaciones sin que ello suponga una bajada de rendimiento.\
							Son especialmente útiles para modelos con muchas relaciones, ya que son más eficientes para consultas donde haya relaciones de proximidad entre los datos que para consultas globales.\
							Pueden ser consistentes o eventualmente consistentes.<br/>\
						</p>\
					</div>';
}

function ir_a_BBDD(i){
	i.innerHTML = ' <div style="width:100%; float:left; text-align:center; color:#045FB4;">\
						<img style="width:70%; height:30%; float:left; padding:3% 15%;" src="./images/arbol_BBDD.png" alt="Arbol BBDD">\
					</div>\
					<div style="width:100%; float:center; text-align:left; color:#045FB4;">\
						<p style="padding:1% 5%;"><span style="font-weight:bold;">Documentales</span>: Almacenan la información de forma semiestructurada, es decir, en documentos cuyo formato puede ser JSON o BSON.\
							Estos documentos son similares a los registros de una BBDD relacional, con la diferencia de que no son tan rígidos; es decir,\
							un documento puede tener unos atributos distintos a los de otro documento, y ambos estar en la misma BBDD.\
							Los documentos están direccionados por una clave única mediante la cual se recupera la información,\
							pero estas BBDD también cuentan con un API que permite recuperar la información asociada a un campo o campos específicos.\
							La gran ventaja de estos sistemas es que puedes introducir un documento entero directamente sin tener que mapearlo primero a ningún modelo, como el entidad-relación,\
							siempre que lo pases a formato JSON primero.Son sistemas que bien pueden ser consistentes o eventualmente consistentes.<br/>\
							<span style="font-weight:bold;">Columnares</span>: Almacenan la información en forma de columnas. Cuentan con una clave primaria para obtener y actualizar los datos.\
							Son parecidas a las BBDD relacionales, pero utilizando columnas en lugar de registros. Están orientadas al tratamiento de grandes cantidades de datos.\
							Son sistemas eventualmente consistentes<br/>\
							<span style="font-weight:bold;">Clave-valor</span>: Almacenan la información mediante tuplas que contienen una clave y un valor. Al igual que las columnares,\
							también cuentan con una clave primaria para obtener y actualizar los datos. A la hora de obtener información, simplemente hay que buscar por la clave para recuperar el valor.\
							Son sistemas eventualmente consistentes.<br/>\
							<span style="font-weight:bold;">Grafo</span>: Almacenan la información en forma de grafos, utilizando los nodos (se muestran mediante círculos) y aristas (se muestran mediante flechas)\
							para representar los datos almacenados. Los nodos representan las entidades, y pueden tener cualquier número de atributos, cada uno como un par clave-valor,\
							así como una etiqueta indicando su rol en el dominio del grafo. Las aristas representan las relaciones entre los nodos, siempre tienen dirección, tipo, nodo inicial y nodo final,\
							y, al igual que éstos, pueden tener cualquier número de atributos. Aunque tengan dirección, las relaciones pueden ser recorridas en ambos sentidos.\
							Gracias a que estas relaciones se almacenan correctamente, dos nodos pueden compartir cualquier número o tipo de relaciones sin que ello suponga una bajada de rendimiento.\
							Son especialmente útiles para modelos con muchas relaciones, ya que son más eficientes para consultas donde haya relaciones de proximidad entre los datos que para consultas globales.\
							Pueden ser consistentes o eventualmente consistentes.<br/>\
						</p>\
					</div>\
					<div style="width:100%; float:center; text-align:left; color:#045FB4;">\
						<p style="padding:1% 5%;"><span style="font-weight:bold;">CA</span>: el sistema garantiza que todos los nodos estén disponibles y que los datos sean consistentes,\
							pero no garantiza que se traten las peticiones si un nodo se separa de la red.<br/>\
							<span style="font-weight:bold;">AP</span>: el sistema garantiza que todas las peticiones serán tratadas, aunque los nodos se separen de la red,\
							pero no garantiza que los datos sean consistentes.<br/>\
							<span style="font-weight:bold;">CP</span>: el sistema garantiza que los datos serán consistentes y que las peticiones serán tratadas,\
							aunque los nodos se separen de la red, pero no garantiza que el sistema responda siempre.<br/>\
						</p>\
					</div>';
}



