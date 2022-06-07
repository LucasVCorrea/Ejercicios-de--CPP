4. Diseñar la especificación e implementar el TDA Catapulta. Una Catapulta posee un contrapeso que le permite lanzar múltiples
proyectiles. Debe proveer operaciones para:

• Crear la catapulta a partir del peso (en kilogramos) de su contrapeso.

• Indicar el peso (en kilogramos) disponible para lanzar un proyectil.

• Cargar: agrega un proyectil, indicando su peso (en kilogramos).

• Descargar: remueve todos los proyectiles antes cargados.

• Disparar: lanza todos los proyectiles cargados, quedando descargada y devolviendo la distancia a la que llegarán
dichos proyectiles

Devolver la cantidad de proyectiles lanzados.

• Devolver la distancia máxima a la que lanzó un proyectil.

Nota: Una Catapulta puede lanzar un grupo de proyectiles cuyo peso acumulado tiene que ser menor a 10 veces el peso de su
contrapeso. La distancia (en metros) del disparo se calcula como: (10 * PesoDelContrapeso – PesoDeLosProyectilesCargados)2
 * K.
