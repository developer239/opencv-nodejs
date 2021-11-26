import { Point } from '../../../index'

describe('[core] Point 2D', () => {
  describe('constructor', () => {
    it('initializes from numbers', () => {
      const point = new Point(10, 20)

      expect(point.x).toStrictEqual(10)
      expect(point.y).toStrictEqual(20)
    })

    it('initializes from Point instance', () => {
      const point = new Point(new Point(20, 30))

      expect(point.x).toStrictEqual(20)
      expect(point.y).toStrictEqual(30)
    })
  })

  describe('methods', () => {
    it('adds two points', () => {
      const point1 = new Point(10, 20)
      const point2 = new Point(15, 50)

      const resultPoint = point1.add(point2)

      expect(resultPoint.x).toStrictEqual(25)
      expect(resultPoint.y).toStrictEqual(70)
    })
  })
})