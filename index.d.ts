export class Point {
  constructor(point: Point);
  constructor(x: number, y: number);
  x: number;
  y: number;
  add(point: Point): Point;
  subtract(point: Point): Point;
}

export class Size {
  constructor();
  constructor(width: number, height: number);
  width: number;
  height: number;
}
